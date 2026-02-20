#include <iostream>
#define ROWS 3
#define COLS 3

using namespace std;

int main()
{
    int Matrix1[ROWS][COLS]={};
    int Matrix2[ROWS][COLS]={};
    int MatrixSum[ROWS][COLS]={};

    for(int i=0; i<ROWS; i++)
    {
        cout<<"Enter the values of Row " << i+1 << " in Matrix 1" <<endl;
        for (int j=0; j<COLS; j++)
        {
            cout<<"Value: " << j+1 << " is: ";
            cin >> Matrix1[i][j];
        }
    }
    cout<<endl;
    for(int i=0; i<ROWS; i++)
    {
        cout<<"Enter the values of Row " << i+1 << " in Matrix 2" <<endl;
        for (int j=0; j<COLS; j++)
        {
            cout<<"Value: " << j+1 << " is: ";
            cin >> Matrix2[i][j];
        }
    }
    for(int i = 0; i<ROWS; i++)
    {
        for(int j = 0; j<COLS; j++)
        {
            MatrixSum[i][j] = Matrix1[i][j] + Matrix2[i][j];
        }
    }
    cout<<endl;
    cout << "\nDisplay Matrix\n";
    for(int i = 0; i<ROWS; i++)
    {
        for(int j = 0; j<COLS; j++)
        {
            cout<<MatrixSum[i][j]<<"\t";
        }
        cout<<endl;

    }
}
