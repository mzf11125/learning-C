#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node *next;
	Node *prev;
	Node()
	{
		val = 0;
		next = prev = NULL;
	}
	Node(int _val)
	{
		val = _val;
		next = prev = NULL;
	}
};

struct PriorityQueue
{
private:
	Node *head;
	Node *tail;
	void pushHead(int val)
	{
		Node *newNode = new Node(val);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		return;
	}
	void pushTail(int val)
	{
		Node *newNode = new Node(val);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
			return;
		}
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		return;
	}
	void popHead()
	{
		if (head == NULL)
			return;
		if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
			return;
		}
		Node *deleted = head;
		head = head->next;
		head->prev = NULL;
		delete deleted;
		return;
	}
	void popTail()
	{
		if (head == NULL)
			return;
		if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
			return;
		}
		Node *deleted = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete deleted;
		return;
	}

public:
	PriorityQueue()
	{
		head = tail = NULL;
	}
	void debug()
	{
		Node *cur = head;
		cout << "Head: ";
		while (cur != NULL)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;

		cur = tail;
		cout << "Tail: ";
		while (cur != NULL)
		{
			cout << cur->val << " ";
			cur = cur->prev;
		}
		cout << endl;
	}
	void insert(int val)
	{
		if (head == NULL || val <= head->val)
		{
			pushHead(val);
			return;
		}
		if (val >= tail->val)
		{
			pushTail(val);
			return;
		}
		Node *cur = head;
		while (cur != NULL)
		{
			if (cur->val <= val && val <= cur->next->val)
			{
				// pushMid
				Node *newNode = new Node(val);
				newNode->prev = cur;
				newNode->next = cur->next;
				cur->next = newNode;
				newNode->next->prev = newNode;
				return;
			}
			cur = cur->next;
		}
		return;
	}
	void erase(int val)
	{
		if (head == NULL)
			return;
		if (head->val == val)
		{
			popHead();
			return;
		}
		if (tail->val == val)
		{
			popTail();
			return;
		}
		Node *cur = head;
		while (cur != NULL)
		{
			if (cur->val == val)
			{
				// popMid
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				delete cur;
				return;
			}
			cur = cur->next;
		}
		return;
	}
	int highest()
	{
		if (tail == NULL)
			return -1;
		return tail->val;
	}
};

int main()
{
	PriorityQueue A;
	A.insert(5);
	A.insert(7);
	A.insert(9);
	A.insert(3);
	A.insert(1);
	A.insert(4);
	A.debug();
	A.erase(5);
	A.debug();
	cout << A.highest() << endl;
}
