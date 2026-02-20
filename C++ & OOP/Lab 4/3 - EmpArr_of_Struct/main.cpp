#include <iostream>

using namespace std;
struct Emp_Struct
{
    int ID, salary,bonus, deduction;
    string name;

};
int main()
{
    float netSalary;
    Emp_Struct emp[5];
    cout << "Enter the Employees information" << endl;

    for(int i=0; i<5; i++)
    {
    cout<<"Enter ID of Employee "<<i+1<<" : ";
    cin>>emp[i].ID;

    cout<<"Enter Name of Employee "<<i+1<<" : ";
    cin>>emp[i].name;

    cout<<"Enter Salary of Employee "<<i+1<<" : ";
    cin>>emp[i].salary;

    cout<<"Enter Bonus of Employee "<<i+1<<" : ";
    cin>>emp[i].bonus;

    cout<<"Enter Deduction of Employee "<<i+1<<" : ";
    cin>>emp[i].deduction;
    cout<<endl;
    }
    cout<<endl;

    for(int i=0; i<5; i++)
    {
    netSalary = emp[i].salary + emp[i].bonus - emp[i].deduction;

    cout<<"ID: "<<emp[i].ID<<"\nName: "<<emp[i].name<<"\nNet Salary: "<<netSalary<<endl;
    }
    return 0;
}
