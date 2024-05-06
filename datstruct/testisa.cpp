#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char *description; // Store the description here
    bool isSlang;
    struct Node *child[128];
} Node;

bool nodeHasChild(Node *node);
void freeNode(Node *node);

Node *createNode() {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->description = NULL;
    newNode->isSlang = false;
    
    for (int i = 0; i < 128; i++) {
        newNode->child[i] = NULL;
    }
    
    return newNode;
}

bool insert(Node **root, const char *slangWord, const char *description) {
    if (*root == NULL) {
        *root = createNode();
    }
    unsigned char *text = (unsigned char *)slangWord;
    Node *temp = *root;
    
    int length = strlen(slangWord);
    for (int i = 0; i < length; i++) {
        if (temp->child[text[i]] == NULL) {
            temp->child[text[i]] = createNode();
        }
        temp = temp->child[text[i]];
    }
    
    if (temp->isSlang) {
        printf("Slang word already exists. Updating the description...\n");
        free(temp->description); // Free the old description
    } else {
        temp->isSlang = true;
    }
    
    temp->description = strdup(description); // Store the new description
    return true;
}

int countWords(char *str) {
    int count = 0;
    bool inWord = false;
    
    while (*str) {
        if (!isspace(*str) && !inWord) {
            count++;
            inWord = true;
        } else if (isspace(*str)) {
            inWord = false;
        }
        str++;
    }
    
    return count;
}

bool search(Node *root, const char *slangWord) {
    unsigned char *text = (unsigned char *)slangWord;
    
    int length = strlen(slangWord);
    Node *temp = root;
    for (int i = 0; i < length; i++) {
        if (temp->child[text[i]] == NULL) {
            printf("There is no word \"%s\" in the dictionary.\n", slangWord);
            return false;
        } else {
            temp = temp->child[text[i]];
        }
    }
    
    if (temp->isSlang) {
        printf("Slang word: %s\n", slangWord);
        printf("Description: %s\n", temp->description);
        return true;
    } else {
        printf("The word \"%s\" is not a slang word.\n", slangWord);
        return false;
    }
}

Node *deleteTree(Node *node, unsigned char *text, bool *deleted) {
    if (node == NULL) return node;
    
    if (*text == '\0') {
        if (node->isSlang) {
            node->isSlang = false;
            free(node->description); // Free the description
            node->description = NULL;
            *deleted = true;
            
            if (!nodeHasChild(node)) {
                free(node);
                node = NULL;
            }
        }
        return node;
    }
    
    node->child[*text] = deleteTree(node->child[*text], text + 1, deleted);
    
    if (*deleted && !nodeHasChild(node) && !node->isSlang) {
        free(node);
        node = NULL;
    }
    
    return node;
}

bool nodeHasChild(Node *node) {
    if (node == NULL) return false;
    
    for (int i = 0; i < 128; i++) {
        if (node->child[i] != NULL) {
            return true;
        }
    }
    return false;
}

bool deleteSlang(Node **root, const char *slangWord) {
    unsigned char *text = (unsigned char *)slangWord;
    bool result = false;
    
    if (*root == NULL) return false;
    
    *root = deleteTree(*root, text, &result);
    return result;
}

void printTree(Node *node, unsigned char *prefix, int length) {
    unsigned char newPrefix[length + 2];
    memcpy(newPrefix, prefix, length);
    newPrefix[length + 1] = 0;
    
    if (node->isSlang) {
        printf("WORD: %s\nDESCRIPTION: %s\n", newPrefix, node->description);
    }
    
    for (int i = 0; i < 128; i++) {
        if (node->child[i] != NULL) {
            newPrefix[length] = i;
            printTree(node->child[i], newPrefix, length + 1);
        }
    }
}

void print(Node *root) {
    if (root == NULL) {
        printf("The trie is empty.\n");
        return;
    }
    
    printf("List of all slang words in the dictionary:\n");
    printTree(root, NULL, 0);
}

void viewAllPrefixes(Node *node, char *prefix, int length, const char *searchPrefix) {
    if (node == NULL) {
        return;
    }
    
    if (strncmp(prefix, searchPrefix, length) == 0 && node->isSlang) {
        printf("%s\nDESCRIPTION: %s\n", prefix, node->description);
    }
    
    for (int i = 0; i < 128; i++) {
        if (node->child[i] != NULL) {
            prefix[length] = i;
            prefix[length + 1] = '\0';
            viewAllPrefixes(node->child[i], prefix, length + 1, searchPrefix);
        }
    }
}

void viewAllSlang(Node *root, const char *prefix) {
    char wordPrefix[100];
    strncpy(wordPrefix, prefix, strlen(prefix));
    viewAllPrefixes(root, wordPrefix, strlen(prefix), prefix);
}

void freeNode(Node *node) {
    if (node == NULL) return;
    
    free(node->description);
    
    for (int i = 0; i < 128; i++) {
        freeNode(node->child[i]);
    }
    
    free(node);
}

int main() {
    Node *root = NULL;
    int choice = 0;
    
    char slangWord[100];
    char description[100];
    
    do {
        printf("Boogle Company\n");
        printf("===========================\n");
        printf("1. Release a new slang word\n");
        printf("2. Search a slang word\n");
        printf("3. View all slang words starting with a certain prefix word\n");
        printf("4. View all slang words\n");
        printf("5. Exit\n");
        printf("Choose: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please try again.\n");
            // Clear the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        
        switch (choice) {
            case 1:
                do {
                    printf("Input a new slang word [Must be more than 1 character and contains no space]: ");
                    if (scanf("%99s", slangWord) != 1) {
                        printf("Invalid input. Please try again.\n");
                        // Clear the input buffer
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF);
                        continue;
                    }
                } while (strlen(slangWord) <= 1 || strchr(slangWord, ' ')!= NULL);

               do {
                   printf("Input a new slang word description [Must be more than 2 words]: ");
                   if (scanf(" %99[^\n]", description) != 1) {
                       printf("Invalid input. Please try again.\n");
                       // Clear the input buffer
                       int c;
                       while ((c = getchar()) != '\n' && c != EOF);
                       continue;
                   }
               } while (countWords(description) <= 2);

               if (insert(&root, slangWord, description)) {
                   printf("Successfully released new slang word.\n");
               }
               break;

           case 2:
               printf("Input a slang word to be searched [Must be more than 1 character and contains no space]: ");
               if (scanf("%99s", slangWord) != 1) {
                   printf("Invalid input. Please try again.\n");
                   // Clear the input buffer
                   int c;
                   while ((c = getchar()) != '\n' && c != EOF);
                   continue;
               }
               if (!search(root, slangWord)) {
                   getchar(); // Wait for the user to press Enter
               }
               break;

           case 3:
               printf("Input a prefix to be searched: ");
               if (scanf("%99s", slangWord) != 1) {
                   printf("Invalid input. Please try again.\n");
                   // Clear the input buffer
                   int c;
                   while ((c = getchar()) != '\n' && c != EOF);
                   continue;
               }
               printf("Words start with \"%s\":\n", slangWord);
               viewAllSlang(root, slangWord);
               getchar(); // Wait for the user to press Enter
               break;

           case 4:
               print(root);
               getchar(); // Wait for the user to press Enter
               break;

           case 5:
               printf("Thank you... Have a nice day :)\n");
               freeNode(root); // Free the memory allocated for the trie
               break;

           default:
               printf("Invalid choice. Please try again.\n");
               break;
       }
   } while (choice != 5);

   return 0;
}