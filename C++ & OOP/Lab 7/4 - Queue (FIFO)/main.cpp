#include <iostream>

using namespace std;
/*///Shift

class Queue
{
private:
    int* Q;
    int Head, Tail;
    int SIZE;

public:
    Queue();
    Queue(int StkSize);
    ~Queue();
    bool IsFull();
    bool IsEmpty();
    void EnQueue(int value);
    int DeQueue();
    int QueuePeak();

};
//---------------------------------------------------------
int main()
{
    Queue Q1;  // Queue Size S1 => 5 parameterless Constructor
    for(int i=0; i<5; i++) //number i enter => i<numbers(8) so it entered 7 enough and the last will be show stack full
    {
        Q1.EnQueue(i+10);
    }

    cout<<" Peak: "<<Q1.QueuePeak()<<endl;
	cout<<" Peak: "<<Q1.QueuePeak()<<endl;

    for(int i=0; i<5; i++)
    {
        cout<<"\n\t DeQueue: "<<Q1.DeQueue();
    }
}
//---------------------------------------------------------
///Methods
///Constructor
Queue :: Queue()
{
    SIZE = 5;

    ///Allocate Q Dunamically
    Q = new int[SIZE];

    Head = Tail = 0;
    cout<<"\n Parameterless Constructor..."<<endl;
}
Queue :: Queue(int QSize)
{
    SIZE = QSize;

    ///Allocate Q Dunamically
    Q = new int[SIZE];

    cout<<"\n one Parameter Constructor..."<<endl;
}
///Destructor
Queue :: ~Queue()
{
    delete[] Q;
    cout<<"\n I am Queue Destructor..."<<endl;
}

///Other functions
bool Queue :: IsFull()
{
    return (Tail == SIZE);
}

bool Queue :: IsEmpty()
{
    return (Head == Tail);
}

 void Queue :: EnQueue(int value)
{
    if (IsFull() == false)
        Q[Tail++] = value; //put on the stack array and increment by 1
    else
        cout<<"\n Queue is full"<<endl;
}

int Queue :: DeQueue()  //Shifting method
{
    if (!IsEmpty())
    {
        int value = Q[0];
        for(int i=0; i<Tail-1; i++)
        {
            Q[i] = Q[i+1];
        }
        Tail--;
        return value;
    }
    else
    {
        cout<<"\n Queue is empty"<<endl;
        return -1;
    }
}

int Queue :: QueuePeak()
{
    if (!IsEmpty())
        return Q[0];
    else
    {
        cout<<"\nQueue is empty"<<endl;
        return -1;
    }
}
*/
//----------------------------------------------------------------
//----------------------------------------------------------------
///Circular
class Queue
{
private:
    int* Q;
    int Head, Tail;
    int SIZE;

public:
    Queue();
    Queue(int StkSize);
    ~Queue();
    bool IsFull();
    bool IsEmpty();
    void EnQueue(int value);
    int DeQueue();
    int QueuePeak();

};
//---------------------------------------------------------
int main()
{
    Queue Q1;  // Queue Size S1 => 5 parameterless Constructor
    for(int i=0; i<4; i++) //number i enter => i<numbers(8) so it entered 7 enough and the last will be show stack full
    {
        Q1.EnQueue(i+10);
    }

    cout<<" Peak: "<<Q1.QueuePeak()<<endl;
	cout<<" Peak: "<<Q1.QueuePeak()<<endl;

    for(int i=0; i<4; i++)
    {
        cout<<"\n\t DeQueue: "<<Q1.DeQueue();
    }
}
//---------------------------------------------------------
///Methods
///Constructor
Queue :: Queue()
{
    SIZE = 5;

    ///Allocate Q Dunamically
    Q = new int[SIZE];

    Head = Tail = 0;
    cout<<"\n Parameterless Constructor..."<<endl;
}
Queue :: Queue(int QSize)
{
    SIZE = QSize;

    ///Allocate Q Dunamically
    Q = new int[SIZE];

    cout<<"\n one Parameter Constructor..."<<endl;
}
///Destructor
Queue :: ~Queue()
{
    delete[] Q;
    cout<<"\n I am Queue Destructor..."<<endl;
}

///Other functions
bool Queue :: IsFull()
{
    return (Head == (Tail + 1) % SIZE);
}

bool Queue :: IsEmpty()
{
    return (Head == Tail);
}

 void Queue :: EnQueue(int value)
{
    if (IsFull() == false)
    {
        Q[Tail] = value;
        Tail = (Tail + 1) % SIZE;
    }
    else
        cout<<"\n Queue is full"<<endl;
}

int Queue :: DeQueue()  //Circular method
{
    if (!IsEmpty())
    {
        int value = Q[Head];
        Head = (Head + 1) % SIZE;
        return value;
    }
    else
    {
        cout<<"\n Queue is empty"<<endl;
        return -1;
    }
}

int Queue :: QueuePeak()
{
    if (!IsEmpty())
        return Q[Head];
    else
    {
        cout<<"\nQueue is empty"<<endl;
        return -1;
    }
}
