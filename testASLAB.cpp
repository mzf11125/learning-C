#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 10

struct User {
    char username[20];
    char password[20];
};

struct User users[MAX_USERS];
int userCount = 0;

void saveUserData() {
    FILE *file = fopen("userdata.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }

    fclose(file);
}

void loadUserData() {
    FILE *file = fopen("userdata.txt", "r");
    if (file == NULL) {
        return; // No file found, assume no users.
    }

    while (fscanf(file, "%s %s", users[userCount].username, users[userCount].password) == 2) {
        userCount++;
    }

    fclose(file);
}

void registerUser() {
    if (userCount < MAX_USERS) {
        printf("Enter a new username: ");
        scanf("%s", users[userCount].username);

        printf("Enter a password: ");
        scanf("%s", users[userCount].password);

        printf("Registration successful for user: %s\n", users[userCount].username);
        userCount++;

        saveUserData();
    } else {
        printf("Maximum number of users reached.\n");
    }
}

bool loginUser() {
    char username[20];
    char password[20];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Welcome, %s!\n", users[i].username);
            return true;
        }
    }

    printf("Login failed. Please check your username and password.\n");
    return false;
}

int main() {
    loadUserData(); // Load user data from the file at the program start.

    int choice;

    while (1) {
        printf("1. Login\n2. Register\n3. Exit\n>> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loginUser();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}