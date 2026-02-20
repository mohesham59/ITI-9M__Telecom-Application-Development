#ifndef NODE_H
#define NODE_H
#include "Employee.h"

class Node
{
public:
    Employee data;
    Node* left;
    Node* right;

    Node(Employee emp) : data(emp), left(NULL), right(NULL) {}

};

#endif // NODE_H
