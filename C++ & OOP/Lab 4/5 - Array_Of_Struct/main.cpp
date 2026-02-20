#include <iostream>
#include <MyLibrary.h>
#include <conio.h>

using namespace std;
struct Emp_Struct
{
    int ID, salary,bonus, deduction;
    string name;

};
void AddNewEmployee(Emp_Struct emp[], int size)
{
    cout << "Enter the Employees information" << endl;

    for(int i=0; i<size; i++)
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
};

void DisplayAllEmployees(Emp_Struct emp[], int size)
{
    float netSalary;
    for(int i=0; i<size; i++)
    {
         if (emp[i].ID != 0)
         {
            netSalary = emp[i].salary + emp[i].bonus - emp[i].deduction;
            cout<<"ID: "<<emp[i].ID<<"\nName: "<<emp[i].name<<"\nNet Salary: "<<netSalary<<endl;
         }
    }
};

void DisplayEmployee(Emp_Struct emp[], int size)
{
    int searchID;
    bool found = false;

    cout << "Enter the ID of Employee: ";
    cin >> searchID;

    for(int i=0; i<size; i++)
    {
        if(searchID == emp[i].ID)
        {
            found = true;
            float netSalary = emp[i].salary + emp[i].bonus - emp[i].deduction;
            cout<<"ID: "<<emp[i].ID<<"\nName: "<<emp[i].name<<"\nNet Salary: "<<netSalary<<endl;
            continue;
        }
    }
    if (!found)
        cout << "Employee not found!" << endl;

};

void DeleteEmployee(Emp_Struct emp[], int size)
{
    int searchID;
    bool found = false;

    cout << "Enter the ID of Employee For Deleting: ";
    cin >> searchID;

    Emp_Struct emptyEmp = {0, 0, 0, 0, ""};
    for(int i=0; i<size; i++)
    {
        if(searchID == emp[i].ID)
        {
            found = true;
            cout<<"The Employee with ID "<<emp[i].ID<<" is Deleted"<<endl;
            fill(emp + i, emp + i + 1, emptyEmp);
            //cout<<"The Employee with ID "<<emp[i].ID<<" is Deleted"<<endl;
        }
    }
    if (!found)
        cout << "Employee not found!" << endl;

};

void DeleteAllEmployee(Emp_Struct emp[], int size)
{

    Emp_Struct emptyEmp = {0, 0, 0, 0, ""};
    for(int i=0; i<size; i++)
    {
        fill(emp, emp + size, emptyEmp);
    }
    cout<<"All Employees are Deleted"<<endl;

};
int main()
{
    string menu[6]= {"New", "Dispaly", "Display All", "Delete", "Delete All", "Exit"};
    const int SIZE = 2;
    int cur = 0;
    char ch=' ';
    int ExitFlag = 0;

    Emp_Struct emp[SIZE];

    do
    {
        textattr(0x07);
        clrscr();
        for (int i=0; i<6; i++)
        {
            if (cur == i)
            {
                textattr(0x70);
            }
            else
            {
                textattr(0x07);
            }
            gotoxy(55, i*3+7);
            cout<<menu[i];
        }

        ch = _getch();
        switch(ch)
        {
            cout<<(int)ch;
            case -32:
            case 0:
            case 224:
                ch = _getch();
                switch (ch)
                    {
                        case 72: // UP
                            cur --;
                            if (cur <0)
                                cur = 5;
                        break;

                        case 80: //Down
                            cur ++;
                            if (cur > 5)
                                cur = 0;
                        break;

                        case 71: //Home
                            cur = 0;
                        break;

                        case 79: //end
                            cur = 5;
                        break;
                    }
            break;

            case 13: //enter
                switch(cur)
                {
                    case 0: //new
                        clrscr();
                        cout<<"\nThis is Add New Employee page ... ^_^"<<endl;
                        AddNewEmployee(emp, SIZE);
                        _getch();
                    break;

                    case 1: //Display
                        clrscr();
                        cout<<"\nThis is Display Employee page ... ^_^"<<endl;
                        DisplayEmployee(emp, SIZE);
                        _getch();
                    break;

                    case 2: //Display All
                        clrscr();
                        cout<<"\nThis is Display Employee page ... ^_^"<<endl;
                        DisplayAllEmployees(emp, SIZE);
                        _getch();
                    break;

                    case 3: //Delete
                        clrscr();
                        cout<<"\nThis is Delete Employee page ... ^_^"<<endl;
                        DeleteEmployee(emp, SIZE);
                        _getch();
                    break;

                    case 4: //Delete All
                        clrscr();
                        cout<<"\nThis is Delete All Employee page ... ^_^"<<endl;
                        DeleteAllEmployee(emp, SIZE);
                        _getch();
                    break;

                    case 5: //Exit
                        ExitFlag = 1;
                        textattr(0x07);
                        clrscr();
                        cout<<"\nBye Bye ... ^_^"<<endl;
                        _getch();
                    break;

                }
            break;

            case 7: //ESC
                ExitFlag = 1;
                textattr(0x07);
                clrscr();
                cout<<"\nBye Bye ... ^_^"<<endl;
                _getch();
            break;


        }
    } while(ExitFlag == 0);
    cout << endl;

return 0;
}

