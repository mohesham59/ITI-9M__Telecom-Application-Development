#include <iostream>

using namespace std;
class myTestClass
{
private:

public:
    int Add(int a, int b)
    {
        cout<<"\nTwo Parameters constructors ";
        return a + b;
    }

    int Add(int a, int b, int c)
    {
        cout<<"\nThree Parameters constructors ";
        return a + b +c;
    }

    void Add(char c1, char c2, char c3)
    {
         cout << "\nConcatenation = " << c1 << c2 << c3;
    }

    //void Add(char str1[], char str2[]) //Array of char
    void Add(char* str1, char* str2)  //pointer of char
    {
        cout << "\nString Concatenation = " << str1 << str2;
    }
};
int main()
{
    myTestClass test;

    cout<<test.Add(5,5);
    cout<<test.Add(5,5,5);
    test.Add('A', 'B', 'C');
    test.Add("Mohamed","Hesham");
    return 0;
}
