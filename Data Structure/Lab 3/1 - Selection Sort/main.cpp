#include <iostream>

using namespace std;
void Swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void selectionSort(int *arr, int n)
{
    int minIdx;
    for(int i = 0; i<n-1; i++)
    {
        minIdx = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        Swap(&arr[minIdx], &arr[i]);
    }
}
int main()
{
    int arr[] = {23, 25, 2, 5, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);
    cout << "Sorted array Selection Sort: ";
    for (int i=0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
