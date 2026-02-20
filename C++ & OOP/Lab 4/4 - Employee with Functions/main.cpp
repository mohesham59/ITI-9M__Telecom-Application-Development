#include <iostream>

using namespace std;
struct Emp_Struct
{
    int ID, salary,bonus, deduction;
    string name;

};
Emp_Struct AddNewEmployee()
{
    Emp_Struct emp;

    cout << "Enter the Employee's information" << endl;
    cout<<"Enter ID of Employee: ";
    cin>>emp.ID;

    cout<<"Enter Name of Employee: ";
    cin>>emp.name;

    cout<<"Enter Salary of Employee: ";
    cin>>emp.salary;

    cout<<"Enter Bonus of Employee: ";
    cin>>emp.bonus;

    cout<<"Enter Deduction of Employee: ";
    cin>>emp.deduction;

    return emp;
};
void DisplayEmployee(Emp_Struct emp)
{
    int netSalary;
    netSalary = emp.salary + emp.bonus - emp.deduction;

    cout<<"ID: "<<emp.ID<<"\nName: "<<emp.name<<"\nNet Salary: "<<netSalary<<endl;
}
int main()
{
    Emp_Struct emp;

    emp = AddNewEmployee();
    DisplayEmployee(emp);
}
