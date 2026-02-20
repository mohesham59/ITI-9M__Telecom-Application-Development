#ifndef QUEUECIRCULAR_H
#define QUEUECIRCULAR_H
#include "LinkedList.h"


class QueueCircular
{
private:
    int *arr;
    int Front , Rear, Count;
    int SIZE;

public:
    QueueCircular(int QSize);
    bool IsFull();
    bool IsEmpty();
    void EnQueue(int _data);
    void DeQueue(int &value);
    int QueuePeak();
    void display();
    int Size();

};

//-----------------------------------
//-----------------------------------
QueueCircular :: QueueCircular(int QSize)
{
    SIZE = QSize;
    arr = new int[QSize];
    Front = Rear = Count = 0;
}

//-----------------------------------
//-----------------------------------
///IsFull
bool QueueCircular :: IsFull()
{
    return Count == SIZE;
}

//-----------------------------------
//-----------------------------------
///IsEmpty
bool QueueCircular :: IsEmpty()
{
    return Count == 0;
}

//-----------------------------------
//-----------------------------------
///EnQueue
void QueueCircular :: EnQueue(int _data)
{
    if (IsFull())
    {
        cout << "Queue is Full\n";
        return;
    }

    arr[Rear] = _data;
    Rear = (Rear+1) % SIZE;
    Count++;
}
//-----------------------------------
//-----------------------------------
///DeQueue
void QueueCircular :: DeQueue(int &value)
{
    if (IsEmpty())
    {
        cout << "Queue is Empty\n";
        return;
    }

    value = arr[Front];
    Front  = (Front +1) % SIZE;
    Count--;
}

//-----------------------------------
//-----------------------------------
///Peak
int QueueCircular :: QueuePeak()
{
    if (IsEmpty())
    {
        cout << "Stack is Empty\n";
        return -1;
    }

    return arr[Front];
}

//-----------------------------------
//-----------------------------------
///display
void QueueCircular :: display()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << "Queue: ";
    int idx = Front;

    for (int i = 0; i < Count; i++)
    {
        cout << arr[idx] << " ";
        idx = (idx + 1) % SIZE;
    }
    cout << endl;
}

//------------------------------------
//------------------------------------
int QueueCircular :: Size()
{
    return Count;
}
#endif // STACKLINKEDLIST_H
