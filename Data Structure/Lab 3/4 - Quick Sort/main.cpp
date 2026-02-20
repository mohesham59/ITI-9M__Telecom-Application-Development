#include <iostream>
using namespace std;

// Function Prototypes
void printArr(int* arr, int Size);
void Swap(int &a, int &b);
int Partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main(){
    int arr[5] = {3, 5, 2, 7, 10};
    quickSort(arr, 0, 4);

    printArr(arr, 5);

}

void printArr(int* arr, int Size){
    for(int Iterator = 0; Iterator < Size; Iterator++){
        cout << arr[Iterator] << "\t";
    }
    cout << endl;
}

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        quickSort(arr, low, pi - 1);   // Left Side
        quickSort(arr, pi + 1, high);  // Right Side
    }
}

int Partition(int arr[], int low, int high) {
    int index = low;

    for (int i = low; i < high; i++) {
        if (arr[i] < arr[high]) {
            Swap(arr[index], arr[i]);
            index++;
        }
    }

    Swap(arr[index], arr[high]);
    return index;
}
