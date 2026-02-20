#include <iostream>
/// Return Multiple values from function "Using Pass By Address"
using namespace std;
void Calculate(int X, int Y, int* SumPtr, int* SubPtr, int* MultipPtr, int* DivPtr)
{
    *SumPtr    = X + Y;
    *SubPtr    = X - Y;
    *MultipPtr = X * Y;

    if(Y != 0)
        *DivPtr = X / Y;
    else
        *DivPtr = 0;
}

int main()
{
    int a, b;
    int sum, sub, mul, div;

    cout << "Enter X: ";
    cin >> a;

    cout << "Enter Y: ";
    cin >> b;

    Calculate(a, b, &sum, &sub, &mul, &div);

    cout << "Sum        = " << sum << endl;
    cout << "Sub        = " << sub << endl;
    cout << "Multiply   = " << mul << endl;
    cout << "Division   = " << div << endl;

    return 0;
}

