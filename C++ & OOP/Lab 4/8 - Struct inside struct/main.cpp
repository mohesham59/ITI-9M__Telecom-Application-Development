#include <iostream>
#include <conio.h>
#include "MyLibrary.h"
using namespace std;

struct Emp_Struct
{
    int ID, salary, bonus, deduction;
    string name;
};

struct Dept
{
    int deptID;
    string deptName;
    int empCount;
    Emp_Struct employees[10];
};

void AddDepartment(Dept& d)
{
    cout << "Enter Department ID: ";
    cin >> d.deptID;

    cout << "Enter Department Name: ";
    cin >> d.deptName;

    cout << "How many employees in this department (max 10)? ";
    cin >> d.empCount;
    if (d.empCount > 10) d.empCount = 10;

    for (int i = 0; i < d.empCount; i++)
    {
        cout << "\n--- Employee " << i + 1 << " ---\n";

        cout << "Enter ID: ";
        cin >> d.employees[i].ID;

        cout << "Enter Name: ";
        cin >> d.employees[i].name;

        cout << "Enter Salary: ";
        cin >> d.employees[i].salary;

        cout << "Enter Bonus: ";
        cin >> d.employees[i].bonus;

        cout << "Enter Deduction: ";
        cin >> d.employees[i].deduction;
    }

    cout << "\nDepartment and employees added successfully.\n";
}

void DisplayDepartment(const Dept& d)
{
    cout << "\n=== Department Info ===\n";
    cout << "Dept ID: " << d.deptID << endl;
    cout << "Dept Name: " << d.deptName << endl;

    cout << "\nEmployees:\n";

    for (int i = 0; i < d.empCount; i++)
    {
        float net = d.employees[i].salary + d.employees[i].bonus - d.employees[i].deduction;

        cout << "\nEmployee " << i + 1 << ":\n";
        cout << "ID: " << d.employees[i].ID << endl;
        cout << "Name: " << d.employees[i].name << endl;
        cout << "Net Salary: " << net << endl;
    }

    if (d.empCount == 0)
        cout << "No employees in this department.\n";
}

int main()
{
    Dept department;
    bool deptAdded = false;

    string menu[3] = {"Add Department", "Display Department", "Exit"};
    int cur = 0;
    char ch;
    int ExitFlag = 0;

    do
    {
        textattr(0x07);
        clrscr();

        for (int i = 0; i < 3; i++)
        {
            if (cur == i)
                textattr(0x70);
            else
                textattr(0x07);

            gotoxy(55, 7 + i * 3);
            cout << menu[i];
        }

        ch = _getch();

        switch (ch)
        {
            case -32:
            case 0:
            case 224:
                ch = _getch();
                if (ch == 72)
                    cur = (cur - 1 + 3) % 3;
                else if (ch == 80)
                    cur = (cur + 1) % 3;
                break;

            case 13:
                clrscr();
                switch (cur)
                {
                    case 0:
                        AddDepartment(department);
                        deptAdded = true;
                        break;

                    case 1:
                        if (deptAdded)
                            DisplayDepartment(department);
                        else
                            cout << "No department added yet.\n";
                        break;

                    case 2:
                        ExitFlag = 1;
                        cout << "Bye Bye ^_^" << endl;
                        break;
                }
                _getch();
                break;

            case 27:
                ExitFlag = 1;
                break;
        }

    } while (!ExitFlag);

    return 0;
}
