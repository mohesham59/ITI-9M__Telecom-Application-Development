#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H
#include "LinkedList.h"


class StackLinkedList
{
private:
    LinkedList* StkList;
    int Top;
    int SIZE;

public:
    StackLinkedList(int StkSize);
    bool IsFull();
    bool IsEmpty();
    void Push(int _data);
    void Pop(int &value);
    int peak();
    void display();

};

//-----------------------------------
//-----------------------------------
StackLinkedList :: StackLinkedList(int StkSize)
{
    SIZE = StkSize;
    StkList = new LinkedList();
    Top = 0;
}

//-----------------------------------
//-----------------------------------
///IsFull
bool StackLinkedList :: IsFull()
{
    return Top == SIZE;
}

//-----------------------------------
//-----------------------------------
///IsEmpty
bool StackLinkedList :: IsEmpty()
{
    return Top == 0;
}

//-----------------------------------
//-----------------------------------
///Push
void StackLinkedList :: Push(int _data)
{
    if (IsFull())
    {
        cout << "Stack is Full\n";
        return;
    }

    StkList->add(_data);
    Top++;
}

//-----------------------------------
//-----------------------------------
///Pop
void StackLinkedList :: Pop(int &value)
{
    if (IsEmpty())
    {
        cout << "Stack is Empty\n";
        return;
    }
    Node* last = StkList->getTail();
    value = last->data;

    StkList->deleteNode(value);
    Top--;
}

//-----------------------------------
//-----------------------------------
///Peak
int StackLinkedList :: peak()
{
    if (IsEmpty())
    {
        cout << "Stack is Empty\n";
        return -1;
    }

    return StkList->getTail()->data;
}

//-----------------------------------
//-----------------------------------
///display
void StackLinkedList :: display()
{
    StkList->display();
}

#endif // STACKLINKEDLIST_H
