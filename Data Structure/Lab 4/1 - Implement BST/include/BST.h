#ifndef BST_H
#define BST_H
#include <iostream>
#include "Node.h"
#include "Employee.h"

using namespace std;
// Class representing a Binary Search Tree storing Employee objects
class BST {
private:
    Node* root;  // Pointer to the root node of the BST

    // Recursive insert function (private helper)
    Node* insert(Node* root, Employee emp) {
        // If tree/subtree is empty → insert new node
        if (root == NULL)
            return new Node(emp);

        // Go left if new ID is smaller
        if (emp.ID < root->data.ID)
            root->left = insert(root->left, emp);

        // Go right if new ID is larger
        else if (emp.ID > root->data.ID)
            root->right = insert(root->right, emp);

        // If ID already exists → do not insert duplicates
        else
            cout << "Duplicate ID not allowed\n";

        return root; // Return updated subtree
    }

    // Inorder Traversal (Left - Root - Right)
    // Preorder (Root - Left - Right)
    // Postorder (Left - Rgiht - Root)
    void inorder(Node* root) {
        if (root == NULL) return;

        //Left
        inorder(root->left);
        //Root
        cout << "ID: " << root->data.ID
             << ", Name: " << root->data.Name
             << ", Age: " << root->data.Age << "\n";
        //Right
        inorder(root->right);
    }

    // Recursive Search by ID
    Node* search(Node* root, int id) {
        // Case 1: Not found OR found
        if (root == NULL || root->data.ID == id)
            return root;

        // Search in left subtree if ID is smaller
        if (id < root->data.ID)
            return search(root->left, id);

        // Else search in right subtree
        return search(root->right, id);
    }

    // Find minimum value (leftmost node)
    Node* findMin(Node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    // Find maximum value (rightmost node)
    Node* findMax(Node* root) {
        while (root && root->right != NULL)
            root = root->right;
        return root;
    }

    // Delete a node by ID (recursive)
    Node* deleteNode(Node* root, int id) {
        if (root == NULL) return root;

        // Move left
        if (id < root->data.ID) {
            root->left = deleteNode(root->left, id);
        }
        // Move right
        else if (id > root->data.ID) {
            root->right = deleteNode(root->right, id);
        }
        // Node found
        else {
            // Case 1: No left child
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            // Case 2: No right child
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children → replace with inorder successor
            Node* temp = findMin(root->right); // smallest in right subtree
            root->data = temp->data;           // copy successor's data
            root->right = deleteNode(root->right, temp->data.ID); // delete successor
        }

        return root; // Return updated subtree
    }

public:
    // Constructor initializes empty tree
    BST() : root(NULL) {}

    // Public insert (calls private recursive version)
    void Insert(Employee emp) {
        root = insert(root, emp);
    }

    // Public inorder traversal
    void InorderTraversal() {
        cout << "Inorder Traversal:\n";
        inorder(root);
    }

    // Public search (returns pointer to Employee)
    Employee* Search(int id) {
        Node* result = search(root, id);
        if (result == NULL)
            return NULL;
        return &(result->data);
    }

    // Public delete by ID
    void Delete(int id) {
        root = deleteNode(root, id);
    }

    // Return pointer to minimum Employee
    Employee* GetMinimum() {
        Node* minNode = findMin(root);
        if (minNode)
            return &(minNode->data);
        return NULL;
    }

    // Return pointer to maximum Employee
    Employee* GetMaximum() {
        Node* maxNode = findMax(root);
        if (maxNode)
            return &(maxNode->data);
        return NULL;
    }
};

#endif // BST_H
