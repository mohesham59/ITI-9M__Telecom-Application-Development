#include <iostream>
using namespace std;
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
};

int main()
{

    Stack s1;  // Stack Size S1 => 5 parameterless Constructor
    for(int i=0; i<5; i++) //number i enter => i<numbers(8) so it entered 7 enough and the last will be show stack full
    {
        s1.Push(i+10);
    }

    cout<<" Peak: "<<s1.Peak()<<endl;
	cout<<" Peak: "<<s1.Peak()<<endl;

    for(int i=0; i<5; i++)
    {
        cout<<"\n\t Pop: "<<s1.Pop();
    }
//--------------------------------------------------------------
    Stack s2;  // Stack Size S2 => 5 parameterless Constructor
    for(int i=0; i<5; i++) //number i enter => i<numbers(8) so it entered 7 enough and the last will be show stack full
    {
        s2.Push(i+10);
    }

    Stack RevStk = s2.Reverse();
    for(int i=0; i<5; i++)
    {
        cout<<"\n\t Reverse: "<<RevStk.Pop();
    }
//	s1.Push(10);
//	s1.Push(20);
//	s1.Push(30);



//  cout<<"\n\t "<<s1.Pop();
//	cout<<"\n\t "<<s1.Pop();
    return 0;
}
