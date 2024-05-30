#include <bits/stdc++.h>
using namespace std;

/* Pseudocode:
   1. Create a new node with the given key.
    2. Perform the normal BST rotation. This is a process used to maintain the balance of a binary search tree. It involves moving nodes around in a specific way to ensure that the tree remains balanced.
   3. Update the height of the nodes.
   4. Get the balance factor of the nodes.
   5. If the balance factor is greater than 1, perform the necessary rotations.
   6. If the balance factor is less than -1, perform the necessary rotations.
   7. Return the new root.


    X                                                   y
   / \                                                  /\
  y  T3   Right rotate ->                              t1  x
 /\         <-Left rotate                                  /\
T1 T2                                                     t2 t3
*/

// Node Struct
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
    Node()
    {
        key = 0;
        height = 1;
        left = NULL;
        right = NULL;
    }
    Node(int _key)
    {
        key = _key;
        left = NULL;
        right = NULL;
    }
};

struct AVL
{
private:
    Node *root;
    int getHeight(Node *cur)
    {
        if (cur == NULL)
        {
            return 0;
        }
        return cur->height;
    }
    void updateHeight(Node *cur)
    {
        cur->height = 1 + max(getHeight(cur->left), getHeight(cur->right));
    }
    int getBalance(Node *cur)
    {
        if (cur == NULL)
            return 0;
        return getHeight(cur->left) - getHeight(cur->right);
    }
    Node *leftRotate(Node *y)
    {
        Node *x = y->right;
        Node *T2 = x->left;
        y->right = T2;
        updateHeight(y);
        x->left = y;
        updateHeight(x);
        return x;
    }
    Node *rightRotate(Node *x)
    {
        Node *y = x->left;
        Node *T2 = y->right;
        x->left = T2;
        updateHeight(x);
        y->right = x;
        updateHeight(y);
        return y;
    }
    Node *rebalancing(Node *cur)
    {
        if (getBalance(cur) > 1) // Cur heavy on left
        {
            if (getBalance(cur->left) < 0) // Cur child heavy on the right
            {
                cur->left = leftRotate(cur->left);
            }
            cur = rightRotate(cur);
        }
        else if (getBalance(cur) < -1) // Cur heavy on right
        {
            if (getBalance(cur->right) > 0)
            {
                cur->right = rightRotate(cur->right); // Cur child heavy on the right
            }
            cur = leftRotate(cur);
        }
        return cur;
    }
    Node *insert(Node *cur, int key)
    {
        if (cur == NULL)
        {
            Node *newNode = new Node(key);
            return newNode;
        }
        if (key < cur->key)
        {
            cur->left = insert(cur->left, key);
        }
        if (key > cur->key)
        {
            cur->right = insert(cur->right, key);
        }
        return cur;
    }
    Node *erase(Node *cur, int key)
    {
        if (cur == NULL)
            return cur;
        if (key < cur->key)
        {
            cur->left = erase(cur->left, key);
            return cur;
        }
        if (key > cur->key)
        {
            cur->right = erase(cur->right, key);
            return cur;
        }
        if (cur->left == NULL && cur->right == NULL)
        {
            delete cur;
            return NULL;
        }
        if (cur->left != NULL && cur->right == NULL)
        {
            Node *ret = cur->left;
            delete cur;
            return ret;
        }
        if (cur->left == NULL && cur->right != NULL)
        {
            Node *ret = cur->right;
            delete cur;
            return ret;
        }
        int predecessor = findMax(cur->left);
        cur->key = predecessor;
        cur->left = erase(cur->left, predecessor);
        return cur;
    }
    int findMax(Node *cur)
    {
        if (cur == NULL)
            return -1;
        if (cur->right == NULL)
            return cur->key;
        return findMax(cur->right);
    }
    bool search(Node *cur, int key)
    {
        if (cur == NULL)
            return false;
        if (key == cur->key)
            return true;
        if (key < cur->key)
            return search(cur->left, key);
        return search(cur->right, key);
    }
    void debug(Node *cur)
    { // inorder traversal
        if (cur == NULL)
            return;
        debug(cur->left);
        cout << cur->key << " ";
        debug(cur->right);
    }

public:
    AVL()
    {
        root = NULL;
    }
    void insert(int key)
    {
        root = insert(root, key);
    }
    void erase(int key)
    {
        root = erase(root, key);
    }
    void debug()
    {
        debug(root);
        cout << endl;
    }
    bool search(int key)
    {
        return search(root, key);
    }
};

int main()
{
    AVL avl;
    avl.insert(5);
    avl.insert(10);
    avl.insert(15);
    avl.insert(20);
    avl.insert(25);
    avl.insert(30);
    avl.debug();
    avl.erase(10);
    avl.debug();
}
