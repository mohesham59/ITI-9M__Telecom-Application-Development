#include <iostream>
using namespace std;

int main()
{
    int row, col;
    int** arr;

    cout << "Enter number of students (rows): ";
    cin >> row;

    cout << "Enter number of subjects (cols): ";
    cin >> col;


    arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }


    for (int i = 0; i < row; i++)
    {
        cout << "\nEnter the degrees of student " << i + 1 << ":\n";
        for (int j = 0; j < col; j++)
        {
            cout << "Degree of subject " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }


    cout << "\nSum of each student:\n";
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << "Sum of student " << i + 1 << " = " << sum << endl;
    }


    cout << "\nAverage of each subject:\n";
    for (int j = 0; j < col; j++)
    {
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += arr[i][j];
        }
        float avg = sum / (float) row;
        cout << "Average of subject " << j + 1 << " = " << avg << endl;
    }


    for (int i = 0; i < row; i++)
        delete[] arr[i];

    delete[] arr;

    return 0;
}
