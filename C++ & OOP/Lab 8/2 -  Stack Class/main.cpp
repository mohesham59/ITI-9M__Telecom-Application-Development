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

public:
    ///Constructor
    Stack()
    {
        SIZE = 5;

        ///Allocate StackArr Dunamically
        StackArr = new int[SIZE];

        Tos = 0;
        cout<<"\n Parameterless Constructor..."<<endl;
    }

    Stack(int StkSize)
    {
        SIZE = StkSize;

        ///Allocate StackArr Dunamically
        StackArr = new int[SIZE];

        Tos = 0;
        cout<<"\n one Parameter Constructor..."<<endl;
    }

    /// Copy Constructor
    Stack(const Stack& STK)
    {
        this->Tos = STK.Tos;
        this->SIZE = STK.SIZE;
        this->StackArr = new int[SIZE]; // allocate new memory
        for(int i=0; i<Tos; i++)
            this->StackArr[i] = STK.StackArr[i]; // deep copy

        cout << "\nCopy Constructor called...";
    }

    ///Destructor
    ~Stack()
    {
        delete[] StackArr;
        cout<<"\n I am Stack Destructor..."<<endl;
    }

    ///Other functions
    bool IsFull()
    {
        return (Tos == SIZE);
    }

    bool IsEmpty()
    {
        return (Tos == 0);
    }

    void Push(int value)
    {
        if (IsFull() == false)
            StackArr[Tos++] = value; //put on the stack array and increment by 1
        else
            cout<<"\n Stack is full"<<endl;
    }

    int Pop()
    {
        if (!IsEmpty())
            return StackArr[--Tos];
        else
        {
            cout<<"\n Stack is empty"<<endl;
            return -1;
        }
    }

    int Peak()
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

    Stack Reverse()
    {
        Stack RevStack(Tos); // select size of new stack from TOs
        for (int i=0; i<Tos; i++)
        {
            RevStack.Push(StackArr[Tos - 1 - i]);
        }
        return RevStack;
    }

    friend void ViewContent(Stack Stk);
};

//void ViewContent(Stack Stk = S2)  //pass by value and go to the copy constructor
void ViewContent(Stack Stk)
{
    cout<<"\n Stack Content: ";
    for(int i=0; i<Stk.Tos; i++)
    {
        cout<<Stk.StackArr[i]<<" ";
    }
};
int main()
{
///************* Copy Ctor Case(1): Pass by value to function ********************
/*
    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    ViewContent(S1);  // pass by value

    cout<<"\nNum = "<<S1.Pop()<<endl;
    cout<<"\nNum = "<<S1.Pop()<<endl;
    return 0;
*/
///************* Copy Ctor Case(2): Return by value from function ********************
/*
    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    Stack SS = S1.Reverse();
    for(int i=0; i<4; i++)
    {
    cout<<"\nPop: "<<SS.Pop();
    }
*/
///************* Copy Ctor Case(3): Create obj in terms of another obj "Explicitly" ********************
    Stack S1;

    S1.Push(10);
    S1.Push(20);
    S1.Push(30);
    S1.Push(40);

    Stack S3 ( S1 );

    for(int i=0; i<10; i++)
        S3.Pop();


    for(int i=0; i<10; i++)
        S3.Push(-1);

    cout<<"\nNum = "<<S1.Pop()<<endl;
    cout<<"\nNum = "<<S1.Pop()<<endl;

    return 0;
}
