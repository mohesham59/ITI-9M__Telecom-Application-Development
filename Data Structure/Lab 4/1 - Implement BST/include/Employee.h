#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
public:
    int ID;
    string Name;
    int Age;

    Employee(int id, string name, int age)
    {
        ID = id;
        Name = name;
        Age = age;
    }
};

#endif // EMPLOYEE_H
