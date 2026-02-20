#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a sentence: ";

    while (true)
    {
        ch = cin.get();
        if (ch == '\n')
            break;

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {

        cout<<ch;
        }

    }
    return 0;
}
