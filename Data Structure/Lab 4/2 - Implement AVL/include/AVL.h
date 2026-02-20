#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "Node.h"
using namespace std;

class AVL
{
private:
    Node* root;

    // ===============================
    // Utility functions
    // ===============================
    int getHeight(Node* node) //length of tree
    {
        return (node == NULL) ? 0 : node->height;
    }

    int getBalance(Node* node) //0 1 -1  |  1< left |  -1>  right
    {
        if (node == NULL) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    int max(int a, int b) //max value between two to get length of node
    {
        return (a > b) ? a : b;
    }

    // ===============================
    // Rotations
    // ===============================
    Node* rightRotate(Node* y)  //Balance > 1
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // ===============================
    // Insert
    // ===============================
    Node* insert(Node* node, Employee emp)
    {
        if (node == NULL)
            return new Node(emp);

        if (emp.ID < node->data.ID)
            node->left = insert(node->left, emp);
        else if (emp.ID > node->data.ID)
            node->right = insert(node->right, emp);
        else
            return node; // No duplicates

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        // LL
        if (balance > 1 && emp.ID < node->left->data.ID)
            return rightRotate(node);

        // RR
        if (balance < -1 && emp.ID > node->right->data.ID)
            return leftRotate(node);

        // LR
        if (balance > 1 && emp.ID > node->left->data.ID)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if (balance < -1 && emp.ID < node->right->data.ID)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // ===============================
    // Inorder Traversal
    // ===============================
    void inorder(Node* root)
    {
        if (!root) return;
        inorder(root->left);
        cout << "ID: " << root->data.ID
             << ", Name: " << root->data.Name
             << ", Age: " << root->data.Age << endl;
        inorder(root->right);
    }

public:
    AVL() : root(NULL) {}

    void Insert(Employee emp)
    {
        root = insert(root, emp);
    }

    void InorderTraversal()
    {
        cout << "Inorder Traversal (AVL):\n";
        inorder(root);
    }
};

#endif
