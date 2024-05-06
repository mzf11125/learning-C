#include <bits/stdc++.h>

using namespace std;


struct Node{
	string Data;
	Node* prev;
	Node* next;


	Node(){
		Data = "";
		prev = next = NULL;
	}	
	
};


struct LinkedList{
	Node *head;
	Node* tail;
	
	LinkedList(){
		head = tail = NULL;
	}
	
	
};



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
