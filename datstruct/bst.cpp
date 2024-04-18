#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left;
	Node *right;
	Node() {
		key = 0;
		left = NULL;
		right = NULL;
	}
	Node(int _key) {
		key = _key;
		left = NULL;
		right = NULL;
	}
};

struct BST {
private:
	Node *root;
	Node* insert(Node *cur, int key) {
		if (cur == NULL) {
			Node *newNode = new Node(key);
			return newNode;
		}
		if (key < cur->key) {
			cur->left = insert(cur->left, key);
		}
		if (key > cur->key) {
			cur->right = insert(cur->right, key);
		}
		return cur;
	}
	Node* erase(Node *cur, int key) {
		if (cur == NULL) return cur;
		if (key < cur->key) {
			cur->left = erase(cur->left, key);
			return cur;
		}
		if (key > cur->key) {
			cur->right = erase(cur->right, key);
			return cur;
		}
		if (cur->left == NULL && cur->right == NULL) {
			delete cur;
			return NULL;
		}
		if (cur->left != NULL && cur->right == NULL) {
			Node *ret = cur->left;
			delete cur;
			return ret;
		}
		if (cur->left == NULL && cur->right != NULL) {
			Node *ret = cur->right;
			delete cur;
			return ret;
		}
		int predecessor = findMax(cur->left);
		cur->key = predecessor;
		cur->left = erase(cur->left, predecessor);
		return cur;
	}
	int findMax(Node *cur) {
		if (cur == NULL) return -1;
		if (cur->right == NULL) return cur->key;
		return findMax(cur->right);
	}
	bool search(Node *cur, int key) {
		if (cur == NULL) return false;
		if (key == cur->key) return true;
		if (key < cur->key) return search(cur->left, key);
		return search(cur->right, key);
	}
	void debug(Node *cur) {	// inorder traversal
		if (cur == NULL) return;
		debug(cur->left);
		cout << cur->key << " ";
		debug(cur->right);
	}
public:
	BST() {
		root = NULL;
	}
	void insert(int key) {
		root = insert(root, key);
	}
	void erase(int key) {
		root = erase(root, key);
	}
	void debug() {
		debug(root);
		cout << endl;
	}
	bool search(int key) {
		return search(root, key);
	}
};

int main() {
	BST A;
	A.insert(5);
	A.insert(3);
	A.insert(2);
	A.insert(1);
	A.insert(4);
	A.insert(7);
	A.insert(9);
	A.insert(8);
	A.insert(10);
	A.debug();
	A.erase(9);
	A.debug();
}
