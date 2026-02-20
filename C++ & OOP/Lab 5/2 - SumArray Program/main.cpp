#include <iostream>
#define SIZE 5
using namespace std;

int SumArray(int *arr, int SIZE)
{
    int sum = 0;
    cout << "Array elements: ";
    for(int i = 0; i < SIZE; i++)
    {
        cout << *(arr + i) << " ";  //*(arr + i) = arr[i]
        sum += *(arr + i);
    }
    cout << endl;
    return sum;
}

int main()
{
    int arr[SIZE];

    cout << "Enter array elements\n";
    for(int i = 0; i < SIZE; i++)
    {
        cout <<"Enter element "<<i+1<<" : ";
        cin >> arr[i];
    }

    int result = SumArray(arr, SIZE);
    cout << "Sum = " << result << endl;

    return 0;
}
