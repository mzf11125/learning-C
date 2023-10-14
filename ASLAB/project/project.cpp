#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 4
#define HASH_TABLE_SIZE 25

struct Grid {
    int cells[GRID_SIZE][GRID_SIZE];
    struct grid* = next;
    struct grid8 = prev;
};

struct UserData {
    char userID[7];
    char username[16];
    int score;
}*head = NULL, *tail = NULL;

struct HashNode {
    struct UserData data;
    struct HashNode* next;
}*head = NULL, *tail = NULL;

struct HashNode* hashTable[HASH_TABLE_SIZE];

void displayMainMenu();
void newGame();
void highscore();
void playGame(struct Grid* gameGrid);
void swipeUp(struct Grid* grid);
void swipeDown(struct Grid* grid);
void swipeLeft(struct Grid* grid);
void swipeRight(struct Grid* grid);
void addRandomTile(struct Grid* grid);
void endGame(struct Grid* gameGrid);
void generateUserID(char* username, char* userID);
void addToHighscore(struct UserData user);

void displayMainMenu() {
    printf("Main Menu\n");
    printf("1. New Game\n");
    printf("2. Highscore\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
}

void newGame() {
    struct Grid gameGrid;
    addRandomTile(&gameGrid);
    addRandomTile(&gameGrid);
    playGame(&gameGrid);
}

void highscore() {
}

void playGame(struct Grid* gameGrid) {
    while (1) {
        int userChoice;
        printf("1. Swipe Up\n");
        printf("2. Swipe Down\n");
        printf("3. Swipe Left\n");
        printf("4. Swipe Right\n");
        printf("5. Exit Game\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &input1);

        switch (input1) {
            case 1:
                swipeUp(gameGrid);
                break;
            case 2:
                swipeDown(gameGrid);
                break;
            case 3:
                swipeLeft(gameGrid);
                break;
            case 4:
                swipeRight(gameGrid);
                break;
            case 5:
                endGame(gameGrid);
                return;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
}

void swipeUp(struct Grid* grid) {
	
}

void swipeDown(struct Grid* grid) {
}

void swipeLeft(struct Grid* grid) {
}

void swipeRight(struct Grid* grid) {
}

void addRandomTile(struct Grid* grid) {
}

void endGame(struct Grid* gameGrid) {
}

void generateUserID(char* username, char* userID) {
}

void addToHighscore(struct UserData user) {
}

int main() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    int input;
    do {
        displayMainMenu();
        scanf("%d", &input);

        switch (input) {
            case 1:
                newGame();
                break;
            case 2:
                highscore();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    } while (1);
    return 0;
}
