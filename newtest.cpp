#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 200
#define MAX_BOOKS 200

struct User {
    char username[20];
    char password[20];
};

struct Book {
    char bookID[10];
    char title[100];
    struct Book* next;
    struct Book* prev;
};

struct User* userHash[MAX_USERS];
struct Book* bookHash[MAX_BOOKS];

int ascii(char* str) {
    int sum = 0;
    for (int i = 0; i < strlen(str); i++) {
        sum += (int)str[i];
    }
    return sum;
}

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

void insertUser(struct User* user) {
    int index = ascii(user->username) % MAX_USERS;

    while (userHashTable[index] != NULL) {
        index = (index + 1) % MAX_USERS;
    }

    userHashTable[index] = user;
}

void insertBook(struct Book* book) {
    int index = 0;

    for (int i = 0; i < strlen(book->bookID); i++) {
        if (i == strlen(book->bookID) - 1) {
            index += (book->bookID);
        }
        else if (i % 2 == 0) {
            index += (ascii(&book->bookID[i]) / 2);
        }
        else {
            index += (int)book->bookID[i];
        }
    }
    index %= MAX_BOOKS;

    if (bookHashTable[index] == NULL) {
        bookHashTable[index] = book;
    }
    else {
        struct Book* current = bookHashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = book;
        book->prev = current;
    }
}

struct User* findUser(char* username, char* password) {
    int index = ascii(username) % MAX_USERS;

    while (userHashTable[index] != NULL) {
        if (strcmp(userHashTable[index]->username, username) == 0
            && strcmp(userHashTable[index]->password, password) == 0) {
            return userHashTable[index];
        }
        index = (index + 1) % MAX_USERS;
    }

    return NULL;
}

void registerUser() {
    char username[20];
    char password[20];

    printf("Enter a username (up to 20 characters): ");
    scanf("%s", username);
    printf("Enter a password (up to 20 characters): ");
    scanf("%s", password);

    struct User* existingUser = findUser(username, password);
    if (existingUser != NULL) {
        printf("User already exists. Registration failed.\n");
    } else {
        struct User newUser;
        strcpy(newUser.username, username);
        strcpy(newUser.password, password);
        insertUser(&newUser);
        printf("User registered successfully.\n");
    }
}

void loginUser() {
    char username[20];
    char password[20];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    struct User* user = findUser(username, password);

    if (user != NULL) {
        printf("Login successful. Welcome, %s!\n", user->username);
    } else {
        printf("Login failed. Invalid username or password.\n");
    }
}

int main() {
    for (int i = 0; i < MAX_USERS; i++) {
        userHashTable[i] = NULL;
    }

    for (int i = 0; i < MAX_BOOKS; i++) {
        bookHashTable[i] = NULL;
    }

    int choice;

    while (1) {
        printf("Main Menu\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
