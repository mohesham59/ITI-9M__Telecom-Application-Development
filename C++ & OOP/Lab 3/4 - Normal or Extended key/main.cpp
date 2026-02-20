#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    cout << "Normal or Extended key" << endl;
    char ch;
    cout << "Enter Character : ";
    ch = _getche();
    cout<<endl<<(int)ch <<endl;
    if(ch == -32 || ch == 0 || ch == 224)
    {
        ch = _getch();
        cout<<"Extended key: "<<(int)ch<<endl;
    }
    else
    {
        cout<<"Normal key: "<<endl;

    }
    return 0;
}
