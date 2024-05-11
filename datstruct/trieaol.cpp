#include <bits/stdc++.h> //Import the C++ library

using namespace std; // Use the standard namespace so we don't have to repeatedly write std everytime

// Node structure for linked list
struct Node
{
    string data; // Declare the data string
    Node *next;  // Next pointer

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
        Node *newNode = new Node(value); //
        if (head == NULL)
        {                   // If head is a null
            head = newNode; //
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {                            // While loop condition as long as the node next to current is not null
                current = current->next; // We set current to the next node of current
            }
            current->next = newNode; // If it null then we new node next to the current node
        }
    }

    bool contains(string value)
    { // Function to chec if hte
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print()
    {                         // Funciton to print the word in the linkedlist
        Node *current = head; // Set the current node as head
        int count = 1;        // Start count from
        while (current != NULL)
        {                                                     // as long as current is not NULL
            cout << count++ << ". " << current->data << endl; // Print the count . and the current data and endl
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
    bool isEndOfWord;       // Variable to indicate for the end of the word
    LinkedList *prefixList; // pointer to a linked list data structure, store the words that share the same prefix represented by the current trienode

    TrieNode()
    { // Declare empty trienode
        for (int i = 0; i < 26; i++)
        {                       // For loop as long as the alphabet
            children[i] = NULL; // Set all children as NULL
        }
        isEndOfWord = false;           // Set the end of the word as false since we just started
        prefixList = new LinkedList(); // Set prefixlist as new linkedlist
    }

    ~TrieNode()
    {                      // Destructor for the Trienode
        delete prefixList; // Delete the prefix list
    }
};

// Trie structure
class Trie
{
    TrieNode *root; // Declare the root of the trienode

public:
    Trie()
    {                          // Empty trienode
        root = new TrieNode(); // declare root as new trienode
    }

    ~Trie()
    {                // Deconstructor for the trie
        delete root; // Delete the root of the trie
    }

    void insert(string word, string desc)
    {                          // Function to insert to the new
        TrieNode *node = root; // Set the trienode node as root
        for (char c : word)
        {                        // Iterate the current caharcther thorugh the word
            int index = c - 'a'; // Set index as current characther - 'a'(64)
            if (!node->children[index])
            {                                           // Condition if children in the index is null
                node->children[index] = new TrieNode(); // Then create a newTrieNode in that children
            }
            node->prefixList->append(word); // Appends the word to the list of prefixes with the current node
            node = node->children[index];   // Moves to the child node at the given index
        }
        node->isEndOfWord = true; //
        node->description = desc; //
    }

    bool search(string word)
    { //
        TrieNode *node = searchNode(word);
        return node != nullptr && node->isEndOfWord;
    }

    string getDescription(string word)
    {
        TrieNode *node = searchNode(word);
        if (node != nullptr && node->isEndOfWord)
        {
            return node->description;
        }
        return "";
    }

    LinkedList startsWith(string prefix)
    { //
        LinkedList results;
        TrieNode *node = searchNode(prefix);
        if (node != nullptr)
        {
            Node *current = node->prefixList->head;
            while (current != NULL)
            {
                results.append(current->data);
                current = current->next;
            }
        }
        return results;
    }

    LinkedList getAllWords()
    {                                    // Function to get all the words in the Trie
        LinkedList results;              // Declare LinkedList results
        collectWords(root, "", results); // Collect all words starting from the root
        return results;                  // Return the list of all words
    }

    TrieNode *searchNode(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (!node->children[index])
            {
                return nullptr;
            }
            node = node->children[index];
        }
        return node;
    }

    void collectWords(TrieNode *node, string word, LinkedList &results)
    {
        if (node->isEndOfWord)
        {
            results.append(word);
        }
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i])
            {
                collectWords(node->children[i], word + char(i + 'a'), results);
            }
        }
    }
};

bool isValidWord(string word)
{ // Function to check if the word has more than one characther

    // Check if the word has more than one character
    if (word.length() <= 1)
    {
        return false;
    }

    // Check if the word contains any spaces
    if (word.find(' ') != string::npos)
    {
        return false;
    }

    // If the word passes both checks, it is considered valid
    return true;
}

bool isValidDescription(string desc)
{
    int spaceCount = 0;
    for (char c : desc)
    { // Current char iterates over the description
        if (c == ' ')
        {                 // if C is space
            spaceCount++; // Space count +1
        }
    }
    return spaceCount > 1; // return if space count is greater than 1
}

int main()
{
    Trie dictionary; // Declare Trie as dictionary
    int choice;      // Create int choice for menu

    do
    { // Do while for loop
        cout << "Boogle Slang Word App" << endl;
        cout << "1. Release a new slang word" << endl;
        cout << "2. Search a slang word" << endl;
        cout << "3. View all slang words starting with a certain prefix word" << endl;
        cout << "4. View all slang words" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string word, desc;
            do
            {
                cout << "Input a new slang word [Must be more than 1 characters and contains no space]: ";
                cin >> word;
            } while (!isValidWord(word));

            do
            {
                cout << "Input a new slang word description [Must be more than 2 words]: ";
                cin.ignore();
                getline(cin, desc);
            } while (!isValidDescription(desc));

            if (dictionary.search(word))
            {
                dictionary.insert(word, desc);
                cout << "Successfully updated a slang word." << endl;
            }
            else
            {
                dictionary.insert(word, desc);
                cout << "Successfully released new slang word." << endl;
            }
            cout << "Press enter to continue..." << endl;
            cin.get();
            break;
        }
        case 2:
        {
            string word;
            do
            {
                cout << "Input a slang word to be searched [Must be more than 1 characters and contains no space]: ";
                cin >> word;
            } while (!isValidWord(word));

            if (dictionary.search(word))
            {
                cout << "Slang word : " << word << endl;
                cout << "Description : " << dictionary.getDescription(word) << endl;
            }
            else
            {
                cout << "There is no word \"" << word << "\" in the dictionary." << endl;
            }
            cout << "Press enter to continue..." << endl;
            cin.get();
            break;
        }
        case 3:
        {
            string prefix;
            cout << "Input a prefix to be searched: ";
            cin >> prefix;

            LinkedList words = dictionary.startsWith(prefix);
            if (words.head == nullptr)
            {
                cout << "There is no prefix \"" << prefix << "\" in the dictionary." << endl;
            }
            else
            {
                cout << "Words starts with \"" << prefix << "\":" << endl;
                words.print();
            }
            cout << "Press enter to continue..." << endl;
            cin.get();
            break;
        }
        case 4:
        {
            LinkedList words = dictionary.getAllWords();
            if (words.head == nullptr)
            {
                cout << "There is no slang word yet in the dictionary." << endl;
            }
            else
            {
                cout << "List of all slang words in the dictionary:" << endl;
                words.print();
            }
            cout << "Press enter to continue..." << endl;
            cin.get();
            break;
        }
        case 5:
        {
            cout << "Thank you... Have a nice day :)" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 5); // End loop if choice is not equal to 5
    return 0;
}
