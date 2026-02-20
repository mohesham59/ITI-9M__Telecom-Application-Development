#include <iostream>

using namespace std;
/* // Pass by Reference
void Swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a, b;
    cout<<"Enter A Number: ";
    cin>>a;
    cout<<"Enter B Number: ";
    cin>>b;

    cout << "Before function call: a = " << a << ", b = " << b << endl;
    Swap(a,b);
    cout << "After function call: a = " << a << ", b = " << b << endl;
    return 0;
}
*/
//-------------------------------------------------------
/* // Pass by Address
void Swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a, b;
    cout<<"Enter A Number: ";
    cin>>a;
    cout<<"Enter B Number: ";
    cin>>b;

    cout << "Before function call: a = " << a << ", b = " << b << endl;
    Swap(&a,&b);
    cout << "After function call: a = " << a << ", b = " << b << endl;
    return 0;
}
*/
//---------------------------------------------------------
/* // Pass by Value
void Swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a, b;
    cout<<"Enter A Number: ";
    cin>>a;
    cout<<"Enter B Number: ";
    cin>>b;

    cout << "Before function call: a = " << a << ", b = " << b << endl;
    Swap(a, b);
    cout << "After function call: a = " << a << ", b = " << b << endl;
    return 0;
}
*/
