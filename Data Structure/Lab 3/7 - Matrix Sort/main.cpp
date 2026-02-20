#include <iostream>
#include <algorithm> // for sort
using namespace std;

int main() {
    int mat[3][3] = { {5, 4, 7}, {1, 3, 8}, {2, 9, 6} };
    int m = 3;
    int n = 3;

    int size = m * n;
    int arr[size];

    int k = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            arr[k++] = mat[i][j];


    sort(arr, arr + size);


    k = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            mat[i][j] = arr[k++];


    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}
