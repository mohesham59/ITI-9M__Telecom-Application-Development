#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {5, 5, 4, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxVal = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > maxVal)
            maxVal = arr[i];

    int freq[maxVal + 1] = {0}; //freq = [0, 0, 0, 0, 2, 2, 1]`
    for(int i = 0; i < n; i++)
        freq[arr[i]]++;


    for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(freq[arr[j]] < freq[arr[j+1]] ||
                   (freq[arr[j]] == freq[arr[j+1]] && arr[j] > arr[j+1])) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
