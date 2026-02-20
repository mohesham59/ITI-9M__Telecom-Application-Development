#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout << "Check Whether a Character is an Alphabet or not!" << endl;
    cout<<"Enter Character: ";
    cin >> ch;

    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        cout<<"Your Character " << ch <<" is Alphabet" <<endl;
    }
    else
    {
        cout << "Your Character is not Alphabet!" << endl;
    }
    return 0;
}
