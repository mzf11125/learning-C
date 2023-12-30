#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 200
#define MAX_BOOKS 200


struct User {
	char username[20];
	char password[20];
}*head=NULL, *tail=NULL;

struct Book {
	char Book[10];
	char title[100];
	struct Book* next;
	struct title* prev;
}*head=NULL,*tail=NULL;

void loadUsers() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        return; 
    }

    while (fscanf(file, "%s %s", users[userCount].username, users[userCount].password) == 2) {
        userCount++;
    }
    
    loadUsers* = prev;
    loadUsers* = next;

    fclose(file);
}

void loadBook() {
    FILE *file = fopen("booklist.txt", "r");
    if (file == NULL) {
        return; 
    }

    while (fscanf(file, "%s %s", users[userCount].username, users[userCount].password) == 2) {
        userCount++;
    }

    fclose(file);
}


int ascii(char* str) {
    int sum = 0;
    for (int i = 0; i < strlen(str); i++) {
        sum += (int)str[i];
    }
    return sum;
}


struct Book* findBook(char* bookID) {
    int index = 0;

    for (int i = 0; i < strlen(bookID); i++) {
        if (i == strlen(bookID) - 1) {
            index += asciiSum(bookID);
        }
        else if (i % 2 == 0) {
            index += (asciiSum(&bookID[i]) / 2);
        }
        else {
            index += (int)bookID[i];
        }
    }
    index %= MAX_BOOKS;

    struct Book* current = bookHashTable[index];
    while (current != NULL) {
        if (strcmp(current->bookID, bookID) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL; 
}


void register() {
    if (userCount < MAX_USERS) {
        printf("Enter a new username: ");
        scanf("%s", users[userCount].username);

        printf("Enter a password: ");
        int c;
        int i = 0;

        while ((c = getchar()) != '\n' && i < 19) {
            if (c != '\r') {
                users[userCount].password[i++] = c;
                putchar('*'); 
            }
        }

        users[userCount].password[i] = '\0';

        printf("\nRegistration successful for user: %s\n", users[userCount].username);
        userCount++;

        saveUserData();
    } else {
        printf("Maximum number of users reached.\n");
    }
}

void login(){
	
}

int main(){
	loadUserData(); 
	loadbooklist();

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
            	system("cls");
                registerUser();
                break;
            case 2:
            	system("cls");
                loginUser();
                break;
            case 3:
            	system("cls");
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please slect 1-3\n");
        }
    }
   
    return 0;
}