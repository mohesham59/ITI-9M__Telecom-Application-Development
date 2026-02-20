#include <iostream>
using namespace std;

///without Cpy Constructor
class Stack
{
    ///Data Member
private:
    //int StackArr[5];
    int* StackArr;
    int Tos;
    int SIZE;
    static int counter;        // static member

public:
    ///Constructor
    Stack();
    Stack(int StkSize);

    ///Copy Constructor
    Stack(const Stack& STK);

    ///Destructor
    ~Stack();

    ///Other functions
    bool IsFull();
    bool IsEmpty();
    void Push(int value);
    int Pop();
    int Peak();
    Stack Reverse();

    /// Operators
    Stack& operator=(const Stack& STK);
    Stack operator+(const Stack& STK);

    /// Friend
    friend void ViewContent(Stack Stk);

    ///Static
    static int getCounter();   // static function

};
//---------------------------------------------------------------------
//---------------------------------------------------------------------
int Stack::counter = 0;

int main()
{
    cout << "===== PROGRAM START =====\n";

    Stack S1, S2, S3;
    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    cout << "\n----- S2 = S1 -----\n";
    S2=S1;
    cout << "S2.Pop(): " << S2.Pop() << endl;

    cout << "\n----- S2.Push(-1) -----\n";
    S2.Push(-1);
    cout << "S1.Pop(): " << S1.Pop() << endl;
/*
S1.Push(...)
S1 = [10, 20, 30, 40]
S2 empty
---------
S2 = S1
S2 = [10, 20, 30, 40]
S2.Pop()  40
S2 = [10, 20, 30]
----------
S1 = [10, 20, 30, 40] dont change
----------
S2.Push(-1)
S2 = [10, 20, 30, -1]
S1 = [10, 20, 30, 40]
------------
S1.Pop()  40
S1 = [10, 20, 30]
*/
    cout << "\n----- S3 = S1 + S2 -----\n";
    S3 = S1 + S2;
    cout << "S3.Pop(): " << S3.Pop() << endl;
/*
Initial State:
S1.Push(...)
S1 = [10, 20, 30, 40]
S2 empty
-----------------------
S2 = S1           // Assignment Operator
S2 = [10, 20, 30, 40]

S2.Pop()  40      // removes last element from S2
S2 = [10, 20, 30]
-----------------------
S1 remains unchanged
S1 = [10, 20, 30, 40]
-----------------------
S2.Push(-1)
S2 = [10, 20, 30, -1]
S1 = [10, 20, 30, 40]
-----------------------
S3 = S1 + S2      // Append Operator
S3 = [10, 20, 30, 40, 10, 20, 30, -1]
            S1      |      S2
-----------------------
S3.Pop()   -1      // removes last element from S3
S3 = [10, 20, 30, 40, 10, 20, 30]
-----------------------
*/

    cout << "\n----- View S3 Content -----\n";
    ViewContent(S3);
    cout << endl;

    cout << "Active Objects = " << Stack::getCounter() << endl;

    cout << "\n===== PROGRAM END =====\n";
    return 0;
}
//---------------------------------------------------------------------
//---------------------------------------------------------------------

///void ViewContent(Stack Stk = S2)  //pass by value and go to the copy constructor
void ViewContent(Stack Stk)
{
    cout<<"\nStack Content: ";
    for(int i=0; i<Stk.Tos; i++)
    {
        cout<<Stk.StackArr[i]<<" ";
    }
    cout << endl;
    cout << "------------------------\n";
}

///Constructor
Stack :: Stack()
{
    SIZE = 5;

    ///Allocate StackArr Dunamically
    StackArr = new int[SIZE];

    Tos = 0;
    counter++;
    cout << "Parameterless Constructor called\n";
    cout << "------------------------\n";
}

Stack :: Stack(int StkSize)
{
    SIZE = StkSize;

    ///Allocate StackArr Dunamically
    StackArr = new int[SIZE];

    Tos = 0;
    counter++;
    cout << "Parameterized Constructor called\n";
    cout << "------------------------\n";
}

/// Copy Constructor
Stack :: Stack(const Stack& STK)
{
    this->Tos = STK.Tos;
    this->SIZE = STK.SIZE;

    this->StackArr = new int[SIZE]; // allocate new memory
    for(int i=0; i<Tos; i++)
        this->StackArr[i] = STK.StackArr[i]; // deep copy

    counter++;
    cout << "Copy Constructor called\n";
    cout << "------------------------\n";
}

///Destructor
Stack :: ~Stack()
{
    delete[] StackArr;

    counter--;
    cout << "Destructor called\n";
    cout << "------------------------\n";
}

///Other functions
bool Stack :: IsFull()
{
    return (Tos == SIZE);
}

bool Stack :: IsEmpty()
{
    return (Tos == 0);
}

void Stack :: Push(int value)
{
    if (IsFull() == false)
        StackArr[Tos++] = value; //put on the stack array and increment by 1
    else
        cout<<"\n Stack is full"<<endl;
}

int Stack :: Pop()
{
    if (!IsEmpty())
        return StackArr[--Tos];
    else
    {
        cout<<"\n Stack is empty"<<endl;
        return -1;
    }
}

int Stack :: Peak()
{
    if (!IsEmpty())
    {
        return StackArr[Tos-1]; //put on the stack array and increment by 1
    }
    else
    {
        cout<<"\n Stack is empty"<<endl;
        return -1;
    }
}

Stack Stack :: Reverse()
{
    Stack RevStack(Tos); // select size of new stack from TOs
    for (int i=0; i<Tos; i++)
    {
        RevStack.Push(StackArr[Tos - 1 - i]);
    }
    return RevStack;
}

int Stack::getCounter()
{
    return counter;
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------

/// Functions Operation
// Assignment Operator S1=S2
Stack& Stack :: operator=(const Stack& STK)
{
    this->Tos = STK.Tos;
    this->SIZE = STK.SIZE;

    delete[] StackArr;

    this->StackArr = new int[SIZE];

    for(int i=0; i<Tos; i++)
        this->StackArr[i] = STK.StackArr[i];

    cout << "Assignment Operator called\n";
    cout << "------------------------\n";
    return *this;

}

// Append Operator S3 = S1 + S2
Stack Stack :: operator+(const Stack& STK)
{
    Stack New;

    New.SIZE = this->Tos + STK.Tos;     // total size
    New.StackArr = new int[New.SIZE];  // allocate

    New.Tos = 0;

    // copy first stack
    for(int i=0; i<Tos; i++)
    {
        New.StackArr[New.Tos++] = this->StackArr[i];
    }

    // append second stack
    for(int i=0; i<STK.Tos; i++)
    {
        New.StackArr[New.Tos++] = STK.StackArr[i];
    }

    cout << "Append Operator called\n";
    cout << "------------------------\n";
    return New;
}

