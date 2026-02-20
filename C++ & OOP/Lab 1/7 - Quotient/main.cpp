#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter number1: ";
    cin >> num1;

    cout << "Enter number2: ";
    cin >> num2;

    int quotient = num1 / num2;
    int remainder = num1 % num2;

    cout << "Quotient = " << quotient << endl;
    cout << "Remainder = " << remainder << endl;

    return 0;
}
