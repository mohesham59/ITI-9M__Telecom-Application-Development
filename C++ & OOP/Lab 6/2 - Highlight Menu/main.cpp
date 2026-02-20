#include <iostream>
#include <MyLibrary.h>
#include <conio.h>

using namespace std;

struct Emp_Struct
{
    int ID, salary, bonus, deduction;
    string name;
};

void AddNewEmployee(Emp_Struct* emp, bool* added, int size)
{
    int index;
    cout << "Enter index (0 to " << size - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= size)
    {
        cout << "Invalid index!\n";
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

void DisplayEmployee(Emp_Struct* emp, bool* added, int size)
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
        cout << "Employee not found!\n";
}

void DisplayAllEmployees(Emp_Struct* emp, bool* added, int size)
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
        cout << "No employees added yet!\n";
}

void DeleteEmployee(Emp_Struct* emp, bool* added, int size)
{
    int searchID;
    bool found = false;

    cout << "Enter ID to delete: ";
    cin >> searchID;

    for (int i = 0; i < size; i++)
    {
        if (added[i] && emp[i].ID == searchID)
        {
            added[i] = false;
            found = true;
            cout << "Employee deleted.\n";
        }
    }

    if (!found)
        cout << "Employee not found!\n";
}

void DeleteAllEmployee(bool* added, int size)
{
    for (int i = 0; i < size; i++)
        added[i] = false;

    cout << "All employees deleted!\n";
}



int main()
{
    int SIZE;
    cout << "Enter number of employees: ";
    cin >> SIZE;

    //  Dynamic arrays - Heap
    Emp_Struct* emp = new Emp_Struct[SIZE];
    bool* added = new bool[SIZE]{false};

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
                if (ch == 72)      // up
                    cur = (cur - 1 + 6) % 6;
                else if (ch == 80) // down
                    cur = (cur + 1) % 6;
                break;

            case 13: // Enter
                clrscr();
                switch (cur)
                {
                    case 0:
                        AddNewEmployee(emp, added, SIZE);
                        break;

                    case 1:
                        DisplayEmployee(emp, added, SIZE);
                        break;

                    case 2:
                        DisplayAllEmployees(emp, added, SIZE);
                        break;

                    case 3:
                        DeleteEmployee(emp, added, SIZE);
                        break;

                    case 4:
                        DeleteAllEmployee(added, SIZE);
                        break;

                    case 5:
                        ExitFlag = 1;
                        cout << "Goodbye ^_^";
                        break;
                }
                _getch();
                break;

            case 27:
                ExitFlag = 1;
                break;
        }

    } while (!ExitFlag);

    // Free memory
    delete[] emp;
    delete[] added;

    return 0;
}
