#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H
#include "LinkedList.h"


class QueueLinkedList
{
private:
    LinkedList* QList;
    int Front, Rear;
    int SIZE;

public:
    QueueLinkedList(int QSize);
    bool IsFull();
    bool IsEmpty();
    void EnQueue(int _data);
    void DeQueue(int &value);
    int QueuePeak();
    void display();

};

//-----------------------------------
//-----------------------------------
QueueLinkedList :: QueueLinkedList(int QSize)
{
    SIZE = QSize;
    QList = new LinkedList();
    Front = Rear = 0;
}

//-----------------------------------
//-----------------------------------
///IsFull
bool QueueLinkedList :: IsFull()
{
    return Rear == SIZE;
}

//-----------------------------------
//-----------------------------------
///IsEmpty
bool QueueLinkedList :: IsEmpty()
{
    return QList->CountElement() == 0;
    //Front == 0;
}

//-----------------------------------
//-----------------------------------
///EnQueue
void QueueLinkedList :: EnQueue(int _data)
{
    if (IsFull())
    {
        cout << "Queue is Full\n";
        return;
    }

    QList->add(_data);
    Rear++;
}
//-----------------------------------
//-----------------------------------
///DeQueue
void QueueLinkedList :: DeQueue(int &value)
{
    if (IsEmpty())
    {
        cout << "Queue is Empty\n";
        return;
    }
    Node* First = QList->getHead();
    value = First->data;

    QList->deleteNode(QList->getHead()->data);
    Front++;
}

//-----------------------------------
//-----------------------------------
///Peak
int QueueLinkedList :: QueuePeak()
{
    if (IsEmpty())
    {
        cout << "Stack is Empty\n";
        return -1;
    }

    return QList->getHead()->data;
}

//-----------------------------------
//-----------------------------------
///display
void QueueLinkedList :: display()
{
    QList->display();
}
#endif // STACKLINKEDLIST_H
