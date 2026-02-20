#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;

    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target);

    else
        return binarySearchRecursive(arr, left, mid - 1, target);
}

int main() {
    int arr[] = {2, 5, 11, 20, 34, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter a number to search: ";
    cin >> target;

    cout << "Iterative search result: ";
    int index = binarySearch(arr, n, target);
    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found" << endl;

    cout << "Recursive search result: ";
    index = binarySearchRecursive(arr, 0, n - 1, target);
    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
