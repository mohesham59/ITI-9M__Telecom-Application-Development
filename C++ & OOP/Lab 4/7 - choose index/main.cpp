#include <iostream>
#include <MyLibrary.h>
#include <conio.h>

using namespace std;

struct Emp_Struct
{
    int ID, salary, bonus, deduction;
    string name;
};


void AddNewEmployee(Emp_Struct emp[], bool added[], int size)
{
    int index;

    cout << "Enter index (0 to " << size - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= size)
    {
        cout << "Invalid index!" << endl;
        return;
    }

    cout << "Enter ID: ";
    cin >> emp[index].ID;

    cout << "Enter Name: ";
    cin >> emp[index].name;

    cout << "Enter Salary: ";
    cin >> emp[index].salary;

    cout << "Enter Bonus: ";
    cin >> emp[index].bonus;

    cout << "Enter Deduction: ";
    cin >> emp[index].deduction;

    added[index] = true;

    cout << "\nEmployee saved at index " << index << endl;
}

void DisplayEmployee(Emp_Struct emp[], bool added[], int size)
{
    int searchID;
    bool found = false;

    cout << "Enter Employee ID: ";
    cin >> searchID;

    for (int i = 0; i < size; i++)
    {
        if (added[i] && emp[i].ID == searchID)
        {
            found = true;
            float net = emp[i].salary + emp[i].bonus - emp[i].deduction;
            cout << "\nID: " << emp[i].ID;
            cout << "\nName: " << emp[i].name;
            cout << "\nNet Salary: " << net << endl;
        }
    }

    if (!found)
        cout << "Employee not found!" << endl;
}


void DisplayAllEmployees(Emp_Struct emp[], bool added[], int size)
{
    bool any = false;

    for (int i = 0; i < size; i++)
    {
        if (added[i])
        {
            any = true;
            float net = emp[i].salary + emp[i].bonus - emp[i].deduction;

            cout << "\nIndex: " << i;
            cout << "\nID: " << emp[i].ID;
            cout << "\nName: " << emp[i].name;
            cout << "\nNet Salary: " << net << endl;
            cout << "-----------------------------\n";
        }
    }

    if (!any)
        cout << "No employees added yet!" << endl;
}


void DeleteEmployee(Emp_Struct emp[], bool added[], int size)
{
    int searchID;
    bool found = false;

    cout << "Enter ID to delete: ";
    cin >> searchID;

    for (int i = 0; i < size; i++)
    {
        if (added[i] && emp[i].ID == searchID)
        {
            found = true;
            added[i] = false;
            cout << "Employee with ID " << searchID << " deleted.\n";
        }
    }

    if (!found)
        cout << "Employee not found!" << endl;
}


void DeleteAllEmployee(Emp_Struct emp[], bool added[], int size)
{
    for (int i = 0; i < size; i++)
        added[i] = false;

    cout << "All employees deleted!" << endl;
}


int main()
{
    const int SIZE = 5;
    Emp_Struct emp[SIZE];
    bool added[SIZE] = {false};

    string menu[6] = {"New", "Display", "Display All", "Delete", "Delete All", "Exit"};
    int cur = 0;
    char ch;
    int ExitFlag = 0;

    do
    {
        textattr(0x07);
        clrscr();

        for (int i = 0; i < 6; i++)
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
                if (ch == 72)      // Up
                    cur = (cur - 1 + 6) % 6;
                else if (ch == 80) // Down
                    cur = (cur + 1) % 6;
                break;

            case 13: // Enter
                clrscr();
                switch (cur)
                {
                    case 0:
                        cout << "=== Add Employee ===\n";
                        AddNewEmployee(emp, added, SIZE);
                        break;

                    case 1:
                        cout << "=== Display Employee ===\n";
                        DisplayEmployee(emp, added, SIZE);
                        break;

                    case 2:
                        cout << "=== Display All ===\n";
                        DisplayAllEmployees(emp, added, SIZE);
                        break;

                    case 3:
                        cout << "=== Delete Employee ===\n";
                        DeleteEmployee(emp, added, SIZE);
                        break;

                    case 4:
                        cout << "=== Delete All ===\n";
                        DeleteAllEmployee(emp, added, SIZE);
                        break;

                    case 5:
                        ExitFlag = 1;
                        cout << "Bye Bye ^_^";
                        break;
                }
                _getch();
                break;

            case 27: // ESC
                ExitFlag = 1;
                break;
        }

    } while (!ExitFlag);

    return 0;
}
