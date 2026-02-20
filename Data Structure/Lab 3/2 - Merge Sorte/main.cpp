#include <iostream>

using namespace std;
void Swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;

}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid); // arr, 0, 2   // 0,1
        mergeSort(arr, mid + 1, right); // arr, 3, 4 // 2,2

        Merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {23, 25, 2, 5, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    cout << "Sorted array Merge Sort: ";
    for (int i=0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
