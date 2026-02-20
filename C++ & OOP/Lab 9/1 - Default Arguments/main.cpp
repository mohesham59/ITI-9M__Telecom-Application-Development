#include <iostream>

using namespace std;
int DefultArgu(int A=0, int B=0, int C=0, int D=0);
int main()
{
    int a=10,b=10,c=20,d=50;

    cout<<"\nSum1: "<<DefultArgu(a,b,c,d);
    cout<<"\nSum2: "<<DefultArgu(a,b,c);
    return 0;
}
int DefultArgu(int A, int B, int C, int D)
{
    return A+B+C+D;
}
