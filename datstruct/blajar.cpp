#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node *prev;
	Node *next;

	Node()
	{
		val = 0;
		prev = next = NULL;
	}

	Node(int val)
	{
		val = this->val;
		prev = next = NULL;
	}
};

struct BST
{
	Node *root;
	BST(){
		root = NULL};
	Node *insert(Node *cur, int key)
	{
	}
};