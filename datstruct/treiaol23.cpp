#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string Data;
    Node *prev;
    Node *next;

    Node() : Data(""), prev(nullptr), next(nullptr) {}
};

struct LinkedList
{
    Node *head, *tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->Data << endl;
            current = current->next;
        }
    }
};

struct TrieNode
{
    TrieNode *children[26];
    string description;
    bool isEndOfWord;
    LinkedList *prefixList;

    TrieNode() : isEndOfWord(false), prefixList(new LinkedList())
    {
        fill(begin(children), end(children), nullptr);
    }

    ~TrieNode()
    {
        delete prefixList;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie() : root(new TrieNode()) {}

    ~Trie()
    {
        // Add destructor logic to delete all TrieNodes
    }

    bool search(const string &word)
    {
        // Implement search logic
        return false;
    }

    void insert(const string &word, const string &description)
    {
        // Implement insert logic
    }

    string getDescription(const string &word)
    {
        // Implement getDescription logic
        return "";
    }

    LinkedList startsWith(const string &prefix)
    {
        // Implement startsWith logic
        return LinkedList();
    }

    LinkedList getAllWords()
    {
        // Implement getAllWords logic
        return LinkedList();
    }
};

bool isValidWord(const string &word)
{
    // Implement isValidWord logic
    return true;
}

bool isValidDescription(const string &desc)
{
    // Implement isValidDescription logic
    return true;
}

int main()
{
    Trie dictionary;
    int choice;

    do
    {
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
            cout << "Thank you... Have a nice day :)" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
