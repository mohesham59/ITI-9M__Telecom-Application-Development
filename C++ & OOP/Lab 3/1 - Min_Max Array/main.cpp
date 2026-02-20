#include <iostream>

using namespace std;

int main()
{
    cout << "Get minimum & maximum value of array elements."<<endl;
    int arr [] = {2,3,4,5,6,7};
    int siz = sizeof(arr)/sizeof(arr[0]);

    int arrMax = arr[0];
    int arrMin = arr[0];

    for (int i=0; i<siz; i++)
    {
        if (arr[i]<arrMin)
            arrMin = arr[i];
        if (arr[i]>arrMax)
            arrMax = arr[i];
    }
    cout<<"Max is: " << arrMax << "\nMin is: " << arrMin <<endl;
    return 0;
}
