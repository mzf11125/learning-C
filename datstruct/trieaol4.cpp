#include <bits/stdc++.h> //Import the C++ library

using namespace std; // Use the standard namespace so we don't have to repeatedly write std everytime

// Node structure for linked list
struct Node
{
    string data; // Declare the data string
    Node *next;  // Next pointer

    Node() // Initialize empty Node
    {
        data = "";
        next = NULL;
    }

    Node(string value)
    {                 // Make the new insterted value as the Data in Node
        data = value; // Set data as value inserted
        next = NULL;  // Set next pointer as null
    }
};
// Linked list structure
struct LinkedList
{
    Node *head; // Create the node head of the LinkedList

public:
    LinkedList()
    {                // Declare empty LinkedList funciton
        head = NULL; // Set pointer to head as null
    }

    ~LinkedList()
    {                         // Destructor to free the memory that was occupied by LinkedList
        Node *current = head; // Declare that current node is head of LinkedList
        while (current != NULL)
        {                            // While loop as long as current is not NULL
            Node *temp = current;    // Set temporary node as current node
            current = current->next; // Set the current node as the next node of current node
            delete temp;             // Delete the temporary node
        }
    }

    void append(string value)
    {                                    // Function to append to the LinkedList
        Node *newNode = new Node(value); // Create a new node with the given value
        if (head == NULL)
        {                   // If head is null
            head = newNode; // Set the new node as the head
        }
        else
        {
            Node *current = head; // Set current node as the head
            while (current->next != NULL)
            {                            // While loop condition as long as the node next to current is not null
                current = current->next; // We set current to the next node of current
            }
            current->next = newNode; // If it's null, then we set the new node as the next node of the current node
        }
    }

    bool contains(string value)
    {                         // Function to check if the linked list contains a specific value
        Node *current = head; // Set current node as the head
        while (current != NULL)
        { // Loop until current is null
            if (current->data == value)
            {                // If the current node's data matches the given value
                return true; // Return true
            }
            current = current->next; // Move to the next node
        }
        return false; // If no match found, return false
    }

    void print()
    {                         // Function to print the words in the linked list
        Node *current = head; // Set the current node as head
        int count = 1;        // Start count from 1
        while (current != NULL)
        {                                                     // as long as current is not NULL
            cout << count++ << ". " << current->data << endl; // Print the count, then the current data, then a new line
            current = current->next;                          // Set current as the next node of current node
        }
    }

    Node *getHead()
    {                // Get the head of the LinkedList
        return head; // return the head
    }
};

// Trie Node structure
struct TrieNode
{
    TrieNode *children[26]; // Children pointer, representing the alphabet from 'a' to 'z'
    string description;     // String to store the description of the word represented by the trienode
    bool isEndOfWord;       // Variable to indicate the end of the word
    LinkedList *prefixList; // pointer to a linked list data structure, store the words that share the same prefix represented by the current trienode

    TrieNode()
    { // Declare empty trienode
        for (int i = 0; i < 26; i++)
        {                       // For loop as long as the alphabet
            children[i] = NULL; // Set all children as NULL
        }
        isEndOfWord = false;           // Set the end of the word as false since we just started
        prefixList = new LinkedList(); // Set prefixList as a new linked list
    }

    ~TrieNode()
    { // Destructor for the Trienode
        if (prefixList != NULL)
        {
            for (int i = 0; i < 26; i++)
            {
                if (children[i] != NULL)
                {
                    delete children[i];
                    children[i] = NULL;
                }
            }
        }
    }
};

// Trie structure
struct Trie
{
    TrieNode *root; // Declare the root of the trienode

public:
    Trie()
    {                          // Empty trienode
        root = new TrieNode(); // declare root as a new trienode
    }

    ~Trie()
    { // Deconstructor for the trie
        if (root != NULL)
        {
            delete root; // Delete the root of the trie
            root = NULL;
        }
    }

    void insert(string word, string desc)
    {                          // Function to insert a new word and description
        TrieNode *node = root; // Set the trienode node as root
        for (char c : word)
        {
            // Iterate over each character in the word
            if (c < 0 || c >= 26)
            {
                // Check if the index is out of bounds
                // Convert the character to lowercase
                c = tolower(c);
                int index = c - 'a';
                // Check if the new index is still out of bounds
                if (index < 0 || index >= 26)
                {
                    cout << "Invalid character: " << c << endl;
                    return;
                }
            }
            if (c >= 'a' && c <= 'z')
            {
                int index = c - 'a';
                // Calculate index as current character minus 'a' (97 ASCII table)

                if (!node->children[index])
                {
                    // Check if the child node at the index is null
                    node->children[index] = new TrieNode();
                    // Create a new TrieNode at that index
                }
                node = node->children[index];
            }
            else
            {
                cout << "Invalid character: " << c << endl;
                return;
            }

            // Move to the child node at the given index
            node->prefixList->append(word);
            // Append the word to the prefix list of the current node
        }
        node->isEndOfWord = true; // Set the current node as the end of the word
        node->description = desc; // Assign the description to the current node
    }

    bool search(string word)
    {                                             // Function to search for a word
        TrieNode *node = searchNode(word);        // Get the node representing the word
        return node != NULL && node->isEndOfWord; // Return true if the node exists and is marked as the end of a word
    }

    string getDescription(string word)
    {                                      // Function to get the description of a word
        TrieNode *node = searchNode(word); // Get the node representing the word
        if (node != NULL && node->isEndOfWord)
        {                             // If the node exists and is marked as the end of a word
            return node->description; // Return the description
        }
        return ""; // Otherwise, return an empty string
    }

    LinkedList startsWith(string prefix)
    {                                        // Function to get all words starting with a given prefix
        LinkedList results;                  // Declare a new linked list to store the results
        TrieNode *node = searchNode(prefix); // Get the node representing the prefix
        if (node != NULL)
        {                                           // If the node exists
            Node *current = node->prefixList->head; // Get the head of the prefix list
            while (current != NULL)
            {                                  // Loop through the prefix list
                results.append(current->data); // Append each word to the results list
                current = current->next;       // Move to the next node
            }
        }
        return results; // Return the results list
    }

    LinkedList getAllWords()
    {                                    // Function to retrieve all words stored in the Trie
        LinkedList results;              // Initialize a new linked list to hold the results
        collectWords(root, "", results); // Utilize the helper function to gather all words
        return results;                  // Return the populated results list
    }

    TrieNode *searchNode(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (!node->children[index])
            {
                return NULL;
            }
            node = node->children[index];
        }
        if (node->isEndOfWord) // Check if the node represents the end of a word
        {
            return node;
        }
        else
        {
            return NULL;
        }
    }

    void collectWords(TrieNode *node, string word, LinkedList &results)
    { // Helper function to collect all words in the Trie
        if (node->isEndOfWord)
        {                         // If the current node marks the end of a word
            results.append(word); // Append the word to the results list
        }
        for (int i = 0; i < 26; i++)
        { // Iterate over all possible characters
            if (node->children[i])
            {                                                                   // If the child node exists
                collectWords(node->children[i], word + char(i + 'a'), results); // Recursively collect words with the current prefix
            }
        }
    }
};

bool isValidWord(string word)
{ // Function to check if the word has more than one character

    // Check if the word has more than one character
    if (word.length() <= 1)
    {
        return false; // If the word has 0 or 1 character, it's not valid
    }

    // Check if the word contains any spaces
    if (word.find(' ') != string::npos)
    {
        return false; // If the word contains spaces, it's not valid
    }

    // If the word passes both checks, it is considered valid
    return true;
}

bool isValidDescription(string desc)
{                       // Function to check if the description is valid
    int spaceCount = 0; // Initialize a variable to count spaces
    for (char c : desc)
    { // Current char iterates over the description
        if (c == ' ')
        {                 // if current char is space
            spaceCount++; // Space count is incremented
        }
    }
    return spaceCount > 1; // return true if space count is greater than 1 (description has to be greater than 2 words)
}

int main()
{
    Trie dictionary; // Declare Trie as dictionary
    int choice;      // Create int choice for menu

    do
    {                                                                                  // Do while loop
        cout << "Boogle Slang Word App" << endl;                                       // Print the app name
        cout << "1. Release a new slang word" << endl;                                 // Print menu option 1
        cout << "2. Search a slang word" << endl;                                      // Print menu option 2
        cout << "3. View all slang words starting with a certain prefix word" << endl; // Print menu option 3
        cout << "4. View all slang words" << endl;                                     // Print menu option 4
        cout << "5. Exit" << endl;                                                     // Print menu option 5
        cout << "Enter your choice: ";                                                 // Prompt user to enter choice
        cin >> choice;                                                                 // Read user's choice
        getchar();
        switch (choice)
        {
        // Switch statement based on user's choice
        case 1:
        {
            // Case 1: Release a new slang word
            string word, desc;
            // Declare strings to store word and description
            do
            {
                cout << "Input a new slang word [Must be more than 1 character and contain no spaces]: ";
                // Prompt for word
                getline(cin, word); // Read word from user
            } while (!isValidWord(word)); // Use logical NOT operator directly

            getchar();

            do
            {
                cout << "Input a new slang word description [Must be more than 2 words]: ";
                // Prompt for description
                getline(cin, desc); // Read description from user
            } while (!isValidDescription(desc)); // Use logical NOT operator directly

            if (dictionary.search(word))
            {
                // If the word already exists in the dictionary
                cout << "The word already exists. Updating the description." << endl;
                dictionary.insert(word, desc);                        // Update the description for the existing word
                cout << "Successfully updated a slang word." << endl; // Print success message
            }
            else
            {
                dictionary.insert(word, desc);                           // Insert the new word and description into the trie
                cout << "Successfully released new slang word." << endl; // Print success message
            }
            cout << "Press enter to continue..." << endl; // Prompt user to press Enter
            // cin.ignore();                                 // Wait for user input (consume the newline character)
            getchar(); // Wait for user input (consume the newline character)

            // Clear the word and desc after case 1 ends
            word.clear();
            desc.clear();
            break; // Break out of the switch statement
        }
        case 2:
        { // Case 2: Search a slang word
            string word;
            do
            {
                cout << "Input a slang word to be searched [Must be more than 1 characters and contains no space]: ";
                cin >> ws;
                getline(cin, word);
                // cin >> word;
            } while (!isValidWord(word));

            getchar();

            if (dictionary.search(word))
            {                                                                        // If the word is found in the dictionary
                cout << "Slang word : " << word << endl;                             // Print the word
                cout << "Description : " << dictionary.getDescription(word) << endl; // Print the description
            }
            else
            {
                cout << "There is no word \"" << word << "\" in the dictionary." << endl; // Print message if word not found
            }
            cout << "Press enter to continue..." << endl; // User has to press enter to continue
            getchar();
            word.clear();
            break;
        }
        case 3:
        { // Case 3: View all slang words starting with a certain prefix
            string prefix;
            cout << "Input a prefix to be searched: "; // Prompt for prefix
            cin >> prefix;                             // Read prefix from user

            LinkedList words = dictionary.startsWith(prefix); // Get the list of words starting with the prefix
            if (words.head == NULL)
            {                                                                                 // If the list is empty
                cout << "There is no prefix \"" << prefix << "\" in the dictionary." << endl; // Print message
            }
            else
            {
                cout << "Words starts with \"" << prefix << "\":" << endl; // Print header
                words.print();                                             // Print the list of words
            }
            cout << "Press enter to continue..." << endl;
            getchar();
            prefix.clear();
            break;
        }
        case 4:
        {                                                // Case 4: View all slang words
            LinkedList words = dictionary.getAllWords(); // Get the list of all words
            if (words.head == NULL)
            {                                                                    // If the list is empty
                cout << "There is no slang word yet in the dictionary." << endl; // Print message
            }
            else
            {
                cout << "List of all slang words in the dictionary:" << endl; // Print header
                words.print();                                                // Print the list of words
            }
            cout << "Press enter to continue..." << endl;
            getchar();
            break;
        }
        case 5:
        {                                                      // Case 5: Exit
            cout << "Thank you... Have a nice day :)" << endl; // Print farewell message
            break;                                             // Break out of the switch statement
        }
        default:
        {                                                        // Default case: Invalid choice
            cout << "Invalid choice. Please try again." << endl; // Print error message
            break;
        }
            //			}
        }
    } while (choice != 5); // End loop if choice is equal to 5 (Exit)
    return 0; // Return 0 to indicate successful program execution
}