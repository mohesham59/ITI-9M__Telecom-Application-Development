#ifndef STACKNEXTGREATER_H
#define STACKNEXTGREATER_H

class StackNextGreater
{
private:
    int stackSize;
    int top;
    int *arr;




public:
    StackNextGreater(int StkSize);
    bool IsFull();
    bool IsEmpty();
    void Push(int _data);
    void Pop(int &value);
    int peak();
    void display();
    int* next_greater(int nums[], int n);


};

//-----------------------------------
//-----------------------------------
StackNextGreater :: StackNextGreater(int _StkSize)
{
    this->stackSize = _StkSize;

    arr = new int[stackSize];
    top = -1;
}

//-----------------------------------
//-----------------------------------
///ISFull
bool StackNextGreater :: IsFull()
{
    return top == stackSize - 1;
}

//-----------------------------------
//-----------------------------------
///IsEmpty
bool StackNextGreater :: IsEmpty()
{
    return top == -1;
}

//-----------------------------------
//-----------------------------------
///Push
void StackNextGreater :: Push(int _data)
{
    if (IsFull())
    {
        cout << "Stack is Full\n";
        return;
    }

    arr[top] = _data;
    top++;
}

//-----------------------------------
//-----------------------------------
///Pop
void StackNextGreater :: Pop(int &value)
{
    if (IsEmpty())
    {
        cout << "Stack is Empty\n";
        return;
    }

    value = arr[top];
    top--;
}

//-----------------------------------
//-----------------------------------
///Peak
int StackNextGreater :: peak()
{
    if (IsEmpty())
    {
        cout << "Stack is Empty\n";
        return -1;
    }

    return arr[top];
}

//-----------------------------------
//-----------------------------------
///display
void StackNextGreater :: display()
{
    if (IsEmpty())
    {
        cout << "Stack is Empty\n";
        return;
    }

    cout << "Stack: ";
    for (int i = 0; i <= top; i++)
        cout << arr[i] << " ";

    cout << endl;
}

//-----------------------------------
//-----------------------------------
///nextGreater
int* StackNextGreater :: next_greater(int nums[], int n)
{
    int* result = new int[n];
    bool flag;

    for (int i = 0; i < n; i++)
    {
        flag = false;

        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                result[i] = nums[j];
                flag = true;
                break;
            }
        }

        if (!flag)
            result[i] = -1;
    }

    return result;
}
#endif // STACKNEXTGREATER_H
