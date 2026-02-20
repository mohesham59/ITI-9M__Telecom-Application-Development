#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
cout << "=== LinkedList Demo ===\n\n";

    LinkedList* List = new LinkedList();

    // -------------------------------
    cout << "--- Adding Elements ---\n";
    List->add(10);
    List->add(20);
    List->add(30);
    List->add(40);
    List->add(50);

    cout << "Original List: ";
    List->display();
    cout << "-------------------------------\n";
    cout << endl;

    // -------------------------------
    cout << "--- Searching Elements ---\n";
    int searchVal = 30;
    if(List->Search(searchVal))
        cout << "Element " << searchVal << " found in the list.\n";
    else
        cout << "Element " << searchVal << " NOT found in the list.\n";

    searchVal = 100;
    if(List->Search(searchVal))
        cout << "Element " << searchVal << " found in the list.\n";
    else
        cout << "Element " << searchVal << " NOT found in the list.\n";
    cout << "-------------------------------\n";
    cout << endl;

    // -------------------------------
    cout << "--- Deleting Elements ---\n";
    List->deleteNode(10);
    List->deleteNode(50);

    cout << "List after deletions\n";
    List->display();
    cout << "-------------------------------\n";
    cout << endl;

    // -------------------------------
    cout << "--- Counting Elements ---\n";
    cout << "Count elements: " << List->CountElement() << endl;
    cout << "-------------------------------\n";
    cout << endl;

    // -------------------------------
    cout << "--- Index Element ---\n";
    List->getDataByIndex(20);
    cout << "-------------------------------\n";
    cout << endl;

    // -------------------------------
    cout << "--- Reversing List ---\n";
    LinkedList* reversedList = List->reversedListNew();
    cout << "Reversed List: ";
    reversedList->display();
    cout << "-------------------------------\n";
    cout << endl;

    delete List;
    delete reversedList;

    cout << "=== End of Demo ===\n";
    return 0;
}
