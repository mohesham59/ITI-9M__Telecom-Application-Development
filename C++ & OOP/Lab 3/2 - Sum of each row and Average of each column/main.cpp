#include <iostream>

using namespace std;

int main()
{
    int arr[3][4]={};
    cout << "Enter the Values\n"<<endl;

    for(int i=0; i<3; i++)
    {
        cout<<endl;
        int sum = 0;
        cout<<"enter the degrees of student " << i+1 <<endl;
        for (int j=0; j<4; j++)
        {
            cout<<"Degree of Subject " << j+1 << " is: ";
            cin >> arr[i][j];
        }
    }
    //sum
    cout << "\nSum of each student:\n";
    for(int k = 0; k<3; k++)
    {
        int sum = 0;
        for(int l = 0; l<4; l++)
        {
            sum += arr[k][l];
        }
        cout << "Sum of student " << k + 1 << " = " << sum << endl;
    }
    //AVG
    cout << "\nAvg of each student:\n";
    for(int k = 0; k<4; k++)
    {
        int sum = 0;
        for(int l = 0; l<3; l++)
        {
            sum += arr[l][k];
        }
        float avg = sum / 3.0;
        cout << "Average of subject " << k + 1 << " = " << avg << endl;
    }

}
