#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define GRID_SIZE 4
#define HASH_TABLE_SIZE 25

// Define a structure for the game grid
struct Grid {
    int cells[GRID_SIZE][GRID_SIZE];
};

struct UserData {
    char userID[7];
    char username[16];
    int score;
};

struct HashNode {
    struct UserData data;
    struct HashNode* next;
};

// Define an array of hash nodes
struct HashNode* hashTable[HASH_TABLE_SIZE];

// Function prototypes
void displayMainMenu();
void newGame();
void highscore();
void playGame();
void swipeUp(struct Grid* grid);
void swipeDown(struct Grid* grid);
void swipeLeft(struct Grid* grid);
void swipeRight(struct Grid* grid);
void addRandomTile(struct Grid* grid);
void endGame();
void generateUserID(char* username, char* userID);
void addToHighscore(struct UserData user);

int main() {
    // Initialize the hash table
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    int choice;
    do {
        displayMainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                newGame();
                break;
            case 2:
                highscore();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (1); // Infinite loop for the main menu
    return 0;
}

void displayMainMenu() {
    printf("Main Menu\n");
    printf("1. New Game\n");
    printf("2. Highscore\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
}

void newGame() {
    // Initialize a new game, set up the grid, and start playing
    
    struct Grid gameGrid;

    // Add logic to set up the initial state of the game grid here
    // You can call functions like addRandomTile to add the first tiles
    // and start the game loop with playGame()
}

void highscore() {
    // Implement the logic for displaying highscores here
    // You can iterate through the hashTable to display the high scores
}

void playGame() {
    // Implement the game loop logic here, which includes user input and game progression
    // You'll need to call functions like swipeUp, swipeDown, swipeLeft, swipeRight,
    // and addRandomTile during the game.

    // Example game loop:
    while (1) {
        // Handle user input for swiping or exiting the game
        // Check for game over conditions
        // Update and display the game grid
        // Add random tiles if necessary
    }
}

void swipeUp(struct Grid* grid) {
    // Implement logic for swiping up on the game grid
    
}

void swipeDown(struct Grid* grid) {
    // Implement logic for swiping down on the game grid
}

void swipeLeft(struct Grid* grid) {
    // Implement logic for swiping left on the game grid
}

void swipeRight(struct Grid* grid) {
    // Implement logic for swiping right on the game grid
}

void addRandomTile(struct Grid* grid) {
    // Add a random tile to the grid with a value (2 or 4) at an empty cell
}

void endGame() {
    // Implement the logic for ending the current game, update the user's score, and save it
    // You may want to call addToHighscore to record the score in the high score list
}

void generateUserID(char* username, char* userID) {
    // Implement a function to generate a unique user ID based on the username
}

void addToHighscore(struct UserData user) {
    // Implement logic to add a user's data (user ID, username, and score) to the high score list
    // Make sure to handle collisions in your hash table.
}
