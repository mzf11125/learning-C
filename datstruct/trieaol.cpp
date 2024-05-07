#include <bits/stdc++.h>

using namespace std;

// Node structure for linked list
struct Node {
    string data;
    Node* next;

    Node(string value) : data(value), next(nullptr) {}//Make the new insterted value as the Data in Node
};

// Linked list class
struct LinkedList {
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void append(string value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool contains(string value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() {
        Node* current = head;
        int count = 1;
        while (current != nullptr) {
            cout << count++ << ". " << current->data << endl;
            current = current->next;
        }
    }

    Node* getHead() {
        return head;
    }
};

// Trie Node structure
struct TrieNode {
    TrieNode* children[26];
    string description;
    bool isEndOfWord;
    LinkedList* prefixList;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
        prefixList = new LinkedList();
    }

    ~TrieNode() {
        delete prefixList;
    }
};

// Trie structure
class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word, string desc) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node->prefixList->append(word);
            node = node->children[index];
        }
        node->isEndOfWord = true;
        node->description = desc;
    }

    bool search(string word) {
        TrieNode* node = searchNode(word);
        return node != nullptr && node->isEndOfWord;
    }

    string getDescription(string word) {
        TrieNode* node = searchNode(word);
        if (node != nullptr && node->isEndOfWord) {
            return node->description;
        }
        return "";
    }

    LinkedList startsWith(string prefix) {
        LinkedList results;
        TrieNode* node = searchNode(prefix);
        if (node != nullptr) {
            Node* current = node->prefixList->head;
            while (current != nullptr) {
                results.append(current->data);
                current = current->next;
            }
        }
        return results;
    }

    LinkedList getAllWords() {
        LinkedList results;
        collectWords(root, "", results);
        return results;
    }

    TrieNode* searchNode(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return nullptr;
            }
            node = node->children[index];
        }
        return node;
    }

    void collectWords(TrieNode* node, string word, LinkedList& results) {
        if (node->isEndOfWord) {
            results.append(word);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                collectWords(node->children[i], word + char(i + 'a'), results);
            }
        }
    }
};

bool isValidWord(string word) {
    return word.length() > 1 && word.find(' ') == string::npos;
}

bool isValidDescription(string desc) {
    int spaceCount = 0;
    for (char c : desc) {
        if (c == ' ') {
            spaceCount++;
        }
    }
    return spaceCount > 0;
}

int main() {
    Trie dictionary;
    int choice;

    do {
        cout << "Boogle Slang Word App" << endl;
        cout << "1. Release a new slang word" << endl;
        cout << "2. Search a slang word" << endl;
        cout << "3. View all slang words starting with a certain prefix word" << endl;
        cout << "4. View all slang words" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string word, desc;
                do {
                    cout << "Input a new slang word [Must be more than 1 characters and contains no space]: ";
                    cin >> word;
                } while (!isValidWord(word));

                do {
                    cout << "Input a new slang word description [Must be more than 2 words]: ";
                    cin.ignore();
                    getline(cin, desc);
                } while (!isValidDescription(desc));

                if (dictionary.search(word)) {
                    dictionary.insert(word, desc);
                    cout << "Successfully updated a slang word." << endl;
                } else {
                    dictionary.insert(word, desc);
                    cout << "Successfully released new slang word." << endl;
                }
                cout << "Press enter to continue..." << endl;
                cin.get();
                break;
            }
            case 2: {
                string word;
                do {
                    cout << "Input a slang word to be searched [Must be more than 1 characters and contains no space]: ";
                    cin >> word;
                } while (!isValidWord(word));

                if (dictionary.search(word)) {
                    cout << "Slang word : " << word << endl;
                    cout << "Description : " << dictionary.getDescription(word) << endl;
                } else {
                    cout << "There is no word \"" << word << "\" in the dictionary." << endl;
                }
                cout << "Press enter to continue..." << endl;
                cin.get();
                break;
            }
            case 3: {
                string prefix;
                cout << "Input a prefix to be searched: ";
                cin >> prefix;

                LinkedList words = dictionary.startsWith(prefix);
                if (words.head == nullptr) {
                    cout << "There is no prefix \"" << prefix << "\" in the dictionary." << endl;
                } else {
                    cout << "Words starts with \"" << prefix << "\":" << endl;
                    words.print();
                }
                cout << "Press enter to continue..." << endl;
                cin.get();
                break;
            }
            case 4: {
                LinkedList words = dictionary.getAllWords();
                if (words.head == nullptr) {
                    cout << "There is no slang word yet in the dictionary." << endl;
                } else {
                    cout << "List of all slang words in the dictionary:" << endl;
                    words.print();
                }
                cout << "Press enter to continue..." << endl;
                cin.get();
                break;
            }
            case 5: {
                cout << "Thank you... Have a nice day :)" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }while(choice!=5);
    return 0;
}
