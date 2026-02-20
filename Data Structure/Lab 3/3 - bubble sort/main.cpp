#include <iostream>

using namespace std;
void Swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubbleSort(int *arr, int n)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = 0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                Swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
int main()
{
    int arr[] = {23, 25, 2, 5, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);
    cout << "Sorted array Bubble Sort: ";
    for (int i=0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
