#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Multiplication Table" << endl;
    cout << "Enter the number please: " << endl;
    cin >> num;

    for (int i=0; i<=12; i++)
    {
        cout<<i<<" * "<<num<<" = "<<i*num<<endl;
    }
    return 0;
}
