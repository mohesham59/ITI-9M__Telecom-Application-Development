#ifndef NODE_H
#define NODE_H
#include <cstddef>
class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int _data)
    {
        data = _data;
        next = prev = NULL;  // Correct
    }
};

#endif // NODE_H
