#include <iostream>

using namespace std;
int power(int base, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    else
       return base * power(base,pow-1);
}
int main()
{
    int num1, num2;
    cout<<"Enter base and power : "<<endl;
    cin>>num1>>num2;

    cout<<"result: "<<power(num1,num2);
    return 0;
}
