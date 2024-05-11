#include<stdio.h> // included for standard input and output
#include<string.h> // included for memory allocation
#include<stdlib.h> // included for string manipulation

// Trie Program

// Because we have 26 letters in the alphabet, then we make
// 26 letters per node
#define N 26

// The Trie Node Structure
struct Trienode{
    // Each node has N children, starting from the root
	char data; // Storing for printing purposes only
	struct Trienode *children[N];
	int is_leaf; // check to see if it's a leaf node
	char *description; // description
};

// Make a node
struct Trienode *make_trienode(char data){
	// Allocate memory for a TrieNode
	struct Trienode *node = (struct Trienode *)calloc(1, sizeof(struct Trienode));
	
	// Initialize children pointers to NULL
	for(int i = 0; i < N; i++){
		node->children[i] = NULL;
	}

	node->is_leaf = 0; // Initialize is_leaf flag to 0 (false)
	node->data = data; // Set the data of the node to the provided character
	node->description = NULL; // Initialize description pointer to NULL
	return node; // Return the newly created node
}

// Insert a word and also with description
struct Trienode *insert_word(struct Trienode *root, char word[], char description[]) {
    if (root == NULL) { // if root is empty
        root = make_trienode('\0'); // create root
    }
    
    struct Trienode *temp = root;
    int idx;
    // Traverse through the word
    for (int i = 0; word[i] != '\0'; i++) {
    	if(word[i] >= 97){ // If the letter is not capital
    		idx = word[i] - 'a';
		}
		else{ // If the letter is capital
			idx = word[i] - 'A';
		}
        
        // Create new node if necessary
        if (temp->children[idx] == NULL){
            temp->children[idx] = make_trienode(word[i]);
        }
        
        // Move on to the next node
        temp = temp->children[idx];
    }
    
    // Mark the last node as leaf and update the description
    temp->is_leaf = 1;
    
    // Free existing description if it exists
    if (temp->description != NULL) {
        free(temp->description);
        printf("Successfully updated a slang word.\n");
    }
    else{
    	printf("Successfully released new slang word.\n");
	}

    // Allocate memory for new description and copy
    temp->description = (char *)malloc(strlen(description) + 1);
    strcpy(temp->description, description);
    
    return root;
}

// Search a word
void search_word(struct Trienode *root, char word[]) {
    struct Trienode *temp = root;
    int position;
    // Traverse through the word
    for (int i = 0; word[i] != '\0'; i++) {
        if(word[i] >= 97){
    		position = word[i] - 'a';
		}
		else{
			position = word[i] - 'A';
		}
		
        if (temp->children[position] == NULL) { // If empty
            printf("There is no word \"%s\" in the dictionary.\n", word);
            return;
        }
        temp = temp->children[position];
    }

    if (temp != NULL && temp->is_leaf == 1) { // If found
        printf("Slang word : %s\n", word);
		printf("Description : %s\n", temp->description);
		
    } else { // If not found
        printf("There is no word \"%s\" in the dictionary.\n", word);
    }
}

// Display all the words based on the searched prefix
void print_words_with_prefix(struct Trienode *node, char prefix[], int *num) {
    if (node == NULL){ // if node is empty then end the function
    	return;
	}

    if (node->is_leaf){ // if the node is a leaf
    	printf("%d. %s\n", *num, prefix);
    	(*num)++; // iterate the number order 
	}
	
	// Traverse through all possible children of the current node
    for (int i = 0; i < N; i++) {
    	// If the child at index i exists
        if (node->children[i] != NULL) {
        	// Create a new prefix by appending the character of the current child to the current prefix
            char new_prefix[strlen(prefix) + 2]; // Allocate memory for the new prefix
            strcpy(new_prefix, prefix); // Copy the existing prefix
            new_prefix[strlen(prefix)] = node->children[i]->data; // Append the character of the child
            new_prefix[strlen(prefix) + 1] = '\0'; // Add null terminator to indicate end of string
            
            print_words_with_prefix(node->children[i], new_prefix, num); // Recursively call the function with the child node and the new prefix
        }
    }
}

// Search a word by its prefix
void search_prefix(struct Trienode *root, char prefix[]) {
    // Traverse the Trie based on the prefix
    struct Trienode *temp = root;
    int position;
    for (int i = 0; prefix[i] != '\0'; i++) { // If it's not capital
        if(prefix[i] >= 97){
    		position = prefix[i] - 'a';
		}
		else{ // If it's capital
			position = prefix[i] - 'A';
		}
        
        if (temp->children[position] == NULL) { // If not found
            printf("There is no prefix \"%s\" in the dictionary.\n", prefix);
            return;
        }
        temp = temp->children[position];
    }

    // If we reach the end of the prefix, print all words with that prefix
    printf("Words starts with \"%s\":\n", prefix);
    int num = 1;
    print_words_with_prefix(temp, prefix, &num);
}

// Print all words
void print_all_words(struct Trienode *root, char *word, int index, int *num){
    if (root == NULL){ // If root is empty
    	return;
	}

    if (root->is_leaf){ // If root is a leaf node
        word[index] = '\0'; // Add null terminator to mark the end of the word.
        printf("%d. %s\n", (*num)++, word); // print word
    }
	
	// traverse through the root
    for (int i = 0; i < N; i++) {
        if (root->children[i] != NULL) {
            word[index] = root->children[i]->data; // Add the character of the child to the word.
            // Recursively call the function with the child node and the updated word.
            print_all_words(root->children[i], word, index + 1, num);
        }
    }
}

int main(){
	// Driver program for the Trie Data Structure Operations
    struct Trienode *root = NULL;
    
    char enter;
    
    do{
    	// Menu
		printf("Welcome to Boogle (Choose input number):\n");
		printf("1. Release a new slang word\n");
		printf("2. Search a slang word\n");
		printf("3. View all slang words starting with a certain prefix word\n");
		printf("4. View all slang words\n");
		printf("5. Exit\n");
		
		// Input number
		int input;
		printf("Input: ");
		scanf("%d", &input); getchar();
		
		char word[100], desc[100]; // Declare string slang word and description
		
		if(input == 1){
			
			// Loop the input until the word is valid
			while(1){ 
				printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
				scanf("%[^\n]", word); getchar();
				
				bool valid = true; // Word validation
				int l = strlen(word); // Measure word length
				if(l <= 1){
					valid = false;
				}
				
				for(int i = 0; i < l; i++){ // Check if there are any spaces
					if(word[i] == ' '){
						valid = false;
						break;
					}
				}
				
				if(valid == false){ // If the word is invalid then repeat the word input
					printf("Invalid word. Please try again.\n");
					continue;
				}
				
				break; // break the loop if word is valid
			}
			
				// Input description
					while(1){
						printf("Input a new slang word description [Must be more than 2 words]: ");
						scanf("%[^\n]", desc); getchar();
						
						char line[100]; // Use line for strtok
						strcpy(line, desc);
						
						int count = 0; // Word count
						char *token = strtok(line, " "); // use strtok to split string
						
						while(token != NULL){ // count how many words
							count++;
							token = strtok(NULL, " ");
						}
						
						if(count <= 2){ // If the description is invalid then repeat the word input
							printf("Invalid description. Please try again.\n");
							continue;
						}
						
						break; // break the loop if desc is valid
					}
							
					if(root == NULL){ // If root is empty
						root = make_trienode('\0'); // Make a new root
					}
						root = insert_word(root, word, desc);
				}
		
		else if(input == 2){
			if(root == NULL){  // If dictionary is empty
				printf("The dictionary is empty.\n");
			}
			
			else{
				
				char target[100]; // Declare searched word
			
				while(1){
					printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
					scanf("%[^\n]", target); getchar(); // Input a word you want to search
				
					bool valid = true; // Word validation
					int l = strlen(target); // Measure word length
					if(l <= 1){
						valid = false;
					}
					
					for(int i = 0; i < l; i++){ // Check if there are any spaces
						if(target[i] == ' '){
							valid = false;
							break;
						}
					}
					
					if(valid == false){ // If the word is invalid then repeat the word input
						printf("Invalid word. Please try again.\n");
						continue;
					}
					
					break; // break the loop if word is valid
			}
			
			search_word(root, target);
				
			}
		}
		
		else if(input == 3){
			if(root == NULL){
				printf("The dictionary is empty.\n");
			}
			
			else{
				char prefix[100]; // Declare string prefix
				printf("Input a prefix to be searched: ");
				scanf("%[^\n]", prefix); getchar(); // Input prefix
			
				search_prefix(root, prefix);
			}
		}
		
		else if(input == 4){
			if(root == NULL){ // If the list is empty
				printf("There is no slang word yet in the dictionary.\n");
			}
			else{
				printf("List of all slang words in the dictionary:\n");
				char list[100];
				int num = 1;
				print_all_words(root, list, 0, &num);
			}
		}
		
		else if(input == 5){
			printf("Thank you... Have a nice day :)\n");
			break;
		}
		
		printf("\n");
		printf("Press enter to continue..."); 
		// Input enter to continue
		scanf("%c", &enter);
		
		system("cls"); // Clear up the output
	} while(enter == '\n'); // If enter then go back to menu
	
	return 0;
}
