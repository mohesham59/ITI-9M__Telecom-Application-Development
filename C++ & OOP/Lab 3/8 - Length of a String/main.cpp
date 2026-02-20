#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    string str;
    int counter=0;
    bool space = false;

    getline(cin,str);
    for(int i=0; str[i] != '\0'; i++)
    {
        counter++;
    }

    cout<<counter;
}
