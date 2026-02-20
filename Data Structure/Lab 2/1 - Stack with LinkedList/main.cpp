#include <iostream>
#include "LinkedList.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#include "QueueLinkedList.h"
#include "QueueCircular.h"
#include "StackNextGreater.h"

using namespace std;

int main()
{
    int x;
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

    cout << "\n-------------------------------\n";
    cout << "-------------------------------\n";

//------------------------------------------
//------------------------------------------

    cout << "\n=== StackLinkedList Demo ===\n\n";

    StackLinkedList stk(5);

    cout << "\nPushing elements...\n";
    stk.Push(10);
    stk.Push(20);
    stk.Push(30);
    stk.Push(40);

    cout << "\nCurrent Stack (LinkedList): ";
    stk.display();

    cout << "\nPeak element = " << stk.peak() << endl;


    cout << "\nPopping...\n";
    stk.Pop(x);
    cout << "Popped: " << x << endl;

    stk.Pop(x);
    cout << "Popped: " << x << endl;

    cout << "\nStack after pop operations: ";
    stk.display();

    cout << "Peak element now = " << stk.peak() << endl;

    cout << "\n-------------------------------\n";
    cout << "-------------------------------\n";

//------------------------------------------
//------------------------------------------


    cout << "\n=== QueueLinkedList Demo ===\n\n";

    QueueLinkedList QueueLs(5);

    cout << "--- EnQueue Elements ---\n";
    QueueLs.EnQueue(10);
    QueueLs.EnQueue(20);
    QueueLs.EnQueue(30);
    QueueLs.EnQueue(40);
    QueueLs.EnQueue(50);

    cout << "Current Queue: ";
    QueueLs.display();
    cout << endl;

    cout << "\nAttempting to EnQueue 60...\n";
    QueueLs.EnQueue(60); // Should print "Queue is Full"

    cout << "\nQueuePeak (Front element): " << QueueLs.QueuePeak() << endl;

    cout << "\nDeQueue operations:\n";
    QueueLs.DeQueue(x);
    cout << "DeQueued: " << x << endl;

    QueueLs.DeQueue(x);
    cout << "DeQueued: " << x << endl;

    cout << "\nQueue after DeQueue operations\n";
    QueueLs.display();
    cout << endl;

    cout << "\nQueuePeak now (Front element): " << QueueLs.QueuePeak() << endl;

    QueueLs.DeQueue(x);
    QueueLs.DeQueue(x);
    QueueLs.DeQueue(x); // DeQueue last element

    cout << "\nQueue after removing all elements\n";
    QueueLs.display();
    cout << endl;

    cout << "\nAttempting DeQueue on empty queue:\n";
    QueueLs.DeQueue(x); // Should print "Queue is Empty"


    cout << "\n-------------------------------\n";
    cout << "-------------------------------\n";

//------------------------------------------
//------------------------------------------

    cout << "\n=== QueueCircular Demo ===\n\n";
    QueueCircular Q(5);   // Queue size = 5
    int value;

    cout << "--- EnQueue Elements ---" << endl;
    Q.EnQueue(10);
    Q.EnQueue(20);
    Q.EnQueue(30);
    Q.EnQueue(40);

    Q.display();
    cout << endl;

    cout << "--- EnQueue more ---" << endl;
    Q.EnQueue(50);
    Q.display();
    cout << endl;

    cout << "--- Try EnQueue when Full ---" << endl;
    Q.EnQueue(60); // print "Queue is Full"
    cout << endl;

    cout << "--- QueuePeak (Front element) ---" << endl;
    cout << "Front = " << Q.QueuePeak() << endl << endl;

    cout << "--- DeQueue Elements ---" << endl;
    Q.DeQueue(value);
    cout << "Dequeued: " << value << endl;

    Q.DeQueue(value);
    cout << "Dequeued: " << value << endl;

    Q.display();
    cout << endl;

    cout << "--- EnQueue after DeQueue (Circular) ---" << endl;
    Q.EnQueue(100);
    Q.EnQueue(200);

    Q.display();
    cout << endl;

    cout << "--- DeQueue until empty ---" << endl;
    while (!Q.IsEmpty())
    {
        Q.DeQueue(value);
        cout << "Dequeued: " << value << endl;
    }

    cout << endl;

    cout << "--- Try DeQueue on empty queue ---" << endl;
    Q.DeQueue(value); // print "Queue is Empty"

    cout << endl;

 //------------------------------------------
//------------------------------------------

    cout << "\n=== next_greater Demo ===\n\n";

    int arr[] = {1, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Input Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    StackNextGreater st(n);
    int* result = st.next_greater(arr, n);

    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;

    delete[] result;

    return 0;
}
