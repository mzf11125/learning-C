#include <bits/stdc++.h>

using namespace std;

struct Node {
private:
    int val;
    Node *next;
    Node *prev;

public:
    Node() {
        val = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int val) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

struct LinkedList {
private:
    Node *head;
    Node *tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void pushHead(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void pushTail(int val) {
        Node *newNode = new Node(val);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void popHead() {
        if (head == NULL) {
            return;
        }

        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node *deletedNode = head;
        head = head->next;
        head->prev = NULL;
        delete deletedNode;
    }

    void popTail() {
        if (tail == NULL) {
            return;
        }

        if (head == tail) {
            delete tail;
            head = NULL;
            tail = NULL;
            return;
        }

        Node *deletedNode = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete deletedNode;
    }

    bool search(int val) {
        Node *curNode = head;
        while (curNode != NULL) {
            if (curNode->val == val) {
                return true;
            }
            curNode = curNode->next;
        }
        return false;
    }

    void debugForward(Node *curNode) {
        if (curNode == NULL) {
            return;
        }

        cout << curNode->val << " ";
        debugForward(curNode->next);
    }

    void debugBackward(Node *curNode) {
        if (curNode == NULL) {
            return;
        }

        debugBackward(curNode->next);
        cout << curNode->val << " ";
    }

    void debug() {
        cout << "Head: ";
        debugForward(head);
        cout << endl;

        cout << "Tail: ";
        debugBackward(tail);
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    myList.pushHead(5);
    myList.pushHead(4);
    myList.pushTail(6);
    myList.pushTail(7);

    cout << "Searching for 4: " << myList.search(4) << endl; // true
    cout << "Searching for 8: " << myList.search(8) << endl; // false

    myList.debug();

    return 0;
}