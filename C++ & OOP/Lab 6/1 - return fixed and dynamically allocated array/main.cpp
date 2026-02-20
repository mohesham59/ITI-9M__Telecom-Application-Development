#include <iostream>

using namespace std;
/*
// Fixed array
// Reading from invalid memory → will likely print garbage values

int* IncrementArray(){
    int myArr[5];

    for(int i=0; i<5; i++)
    {
        cout<<"Enter Ur Array Element "<< i+1 <<" : ";
        cin>>myArr[i];
        myArr[i]+=10;
    }
    return myArr;
}
int main()
{
    int* ResArr;

    ResArr = IncrementArray();

    cout<<"\nArray Elements After Calling function ";
    for(int i=0; i<5; i++)
    {
        cout<<endl<<ResArr[i]<< " "<<endl;
    }

}
*/
//-----------------------------------------------------------
/*
// Dynamically allocated array
// Print the array elements after increment
 int* IncrementArray()
 {
    int* myArr = new int [5];
    for(int i=0; i<5; i++)
    {
        cout<<"Enter Ur Array Element "<< i+1 <<" : ";
        cin>>myArr[i];
        myArr[i]+=10;
    }
     return myArr;
 }

 int main()
 {
    int* ResArr;
    ResArr = IncrementArray();
    cout<<"\nArray Elements after calling function: ";

    for(int i=0; i<5; i++)
    {
        cout<<endl<<ResArr[i]<< " "<<endl;
    }

     delete[] ResArr;  //Release dynamic alloc memory in heap
 }
*/
