#include <iostream>
#include <string>

using namespace std;
int largestnumber(int a, int b, int c)
{
    if(a>b && a>c)
        return a;
        //cout<<"num1 is largest: "<<a<<endl;
    else if (b>a && b>c)
        return b;
        //cout<<"num2 is largest: "<<b<<endl;
    else
        return c;
        //cout<<"num3 is largest: "<<c<<endl;
}
int main()
{
    int num1, num2, num3;
    cout<<"Enter number 1: ";
    cin>>num1;
    cout<<"Enter number 2: ";
    cin>>num2;
    cout<<"Enter number 3: ";
    cin>>num3;

    cout<<"The Largest Number is: "<<largestnumber(num1,num2,num3);

    return 0;
}
