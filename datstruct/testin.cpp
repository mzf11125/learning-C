#include <bits/stdc++.h>
using namespace std;

// struct //structure -> similar to class

struct dataStudent
{ // Constructor
    string name;
    string ID;
    string number;

    dataStudent()
    { // empty data
        name = " ";
        ID = " ";
        number = " ";
    }

    dataStudent(string name, string ID, string number)
    {
        this->name = name;
        this->ID = ID;
        this->number = number;
    }
};

// struct Node

struct Node
{
    dataStudent dt;
    Node *next;
    Node *prev;

    Node()
    {
        dt = dataStudent();
        next = NULL;
        prev = NULL;
    }
    Node(dataStudent dt)
    {
        this->dt = dt;
        next = NULL;
        prev = NULL;
    }
};

struct doublyLinkedList
{

private:
    Node *head;
    Node *tail;

public:
    Node *getHead()
    {
        return head;
    }

    Node *getTail()
    {
        return tail;
    }

    void setHead(Node *newHead)
    {
        head = newHead;
    }

    void setTail(Node *newTail)
    {
        tail = newTail;
    }

    doublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void addNode(dataStudent dt)
    {
        Node *newNode = new Node(dt);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->dt.name << " " << temp->dt.ID << " " << temp->dt.number << endl;
            temp = temp->next;
        }
    }

    void deleteNode(string ID)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->dt.ID == ID)
            {
                if (temp->prev == NULL)
                {
                    head = temp->next;
                    temp->next->prev = NULL;
                }
                else if (temp->next == NULL)
                {
                    tail = temp->prev;
                    temp->prev->next = NULL;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    doublyLinkedList list;
    string name, ID, number;
    int loop;
    cout << "Enter the number of students: ";
    cin >> loop;
    for (int i = 0; i < loop; i++)
    {
        cout << "Enter the name, ID, and number of student " << i + 1 << ": ";
        cin >> name >> ID >> number;
        list.addNode(dataStudent(name, ID, number));
    }

    cout << "Taking a break brb :)" << endl;
}