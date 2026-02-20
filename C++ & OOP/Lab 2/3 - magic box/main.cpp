#include <iostream>
#include "MyLibrary.h"
using namespace std;

int main()
{
    int n;
    cout << "Hello To the Magic Box" << endl;
    cout << "Enter the size of the box: ";
    cin >> n;
    cout <<endl;

    if(n%2==0)
    {
        cout<<"Your enter even size, please enter odd only"<<endl;
    }
    else
    {
        // initialization
        int row = 1;
        int col = (n+1)/2;

        for (int i =1; i<= n*n ; i++)
        {
            gotoxy(col*8,row+2);
            cout<<i;

            if (i%n == 0)
            {
                row++;
            }
            else
            {
                row--;
                col--;
            }

            if(row == 0)
            {
                row = n;
            }
            if (row == n + 1 )
            {
                row = 1;
            }
            if (col == 0)
            {
                col = n;
            }
            if (col == n + 1)
            {
                col = 1;
            }
            cout <<endl;
        }
    }
    return 0;
}
