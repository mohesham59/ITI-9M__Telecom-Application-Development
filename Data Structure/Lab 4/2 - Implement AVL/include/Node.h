#ifndef NODE_H
#define NODE_H
#include "Employee.h"

class Node
{
public:
    Employee data;
    Node* left;
    Node* right;
    int height;

    Node(Employee emp)
        : data(emp), left(NULL), right(NULL), height(1) {}
};

#endif
