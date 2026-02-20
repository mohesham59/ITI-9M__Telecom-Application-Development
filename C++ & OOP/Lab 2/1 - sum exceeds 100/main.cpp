#include <iostream>

using namespace std;

int main()
{
    cout << "Hello User" << endl;
    int sum=0;
    int num=0;
    while (sum < 100)
    {
        cout <<"Enter the number please: ";
        cin >> num;
        sum += num;
        cout <<"sum is : "<<sum<<endl;

    }
    return 0;
}
