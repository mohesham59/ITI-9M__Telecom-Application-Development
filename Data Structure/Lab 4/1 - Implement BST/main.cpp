#include <iostream>
#include "BST.h"
#include "Node.h"
#include "Employee.h"

using namespace std;

int main()
{
    // ============================
    // Create an empty BST
    // ============================
    BST tree;
    cout << "===== BST Operations Start =====\n\n";

    // ============================
    // Insert employees into the tree
    // ============================
    cout << ">>> Inserting Employees...\n";
    tree.Insert(Employee(101, "Mohamed", 30));
    tree.Insert(Employee(50, "Hesham", 25));
    tree.Insert(Employee(150, "ail", 40));
    tree.Insert(Employee(75, "mona", 28));
    tree.Insert(Employee(120, "ziad", 35));


    // ============================
    // Display the tree using inorder traversal
    // ============================
    cout << "\nCurrent Inorder Traversal of BST:\n";
    tree.InorderTraversal();
    cout << "---------------------------------\n";


    // ============================
    // Search for an employee by ID
    // ============================
    int searchID = 75;
    cout << "\n>>> Searching for Employee with ID " << searchID << "...\n";
    Employee* emp = tree.Search(searchID);

    if (emp)
        cout << "\nFound Employee with ID " << searchID
             << ": " << emp->Name << ", Age: " << emp->Age << endl;
    else
        cout << "\nEmployee with ID " << searchID << " not found.\n";

    cout << "---------------------------------\n";


    // ============================
    // Delete an employee from the tree by ID
    // ============================
    int deleteID = 50;
    cout << "\n>>> Deleting Employee with ID " << deleteID << "...\n";
    tree.Delete(deleteID);
    cout << "\nAfter deleting employee with ID " << deleteID << ":\n";

    // Display the tree after deletion
    tree.InorderTraversal();
    cout << "---------------------------------\n";


    // ============================
    // Get the employee with minimum and maximum ID
    // ============================
    cout << "\n>>> Minimum and Maximum Employee by ID:\n";
    Employee* minEmp = tree.GetMinimum();
    if (minEmp)
        cout << "\nEmployee with Minimum ID: " << minEmp->Name
             << ", ID: " << minEmp->ID << endl;

    Employee* maxEmp = tree.GetMaximum();
    if (maxEmp)
        cout << "Employee with Maximum ID: " << maxEmp->Name
             << ", ID: " << maxEmp->ID << endl;

    // ============================
    // End of program
    // ============================
    cout << "\n===== BST Operations End =====\n";
    return 0;
}
