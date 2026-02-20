#include <iostream>
#include "AVL.h"
using namespace std;

int main()
{
    AVL tree;

    tree.Insert(Employee(101, "Mohamed", 30));
    tree.Insert(Employee(50, "Hesham", 25));
    tree.Insert(Employee(150, "Ali", 40));
    tree.Insert(Employee(75, "Mona", 28));
    tree.Insert(Employee(120, "Ziad", 35));

    cout << "\n";
    tree.InorderTraversal();

    return 0;
}
