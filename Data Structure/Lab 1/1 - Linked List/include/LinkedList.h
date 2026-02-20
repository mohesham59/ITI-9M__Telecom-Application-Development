#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>

#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList
{
private:
    Node* Head;
    Node* Tail;

    Node* getNode(int data)
    {
        Node* current = Head;
        while(current != NULL)
        {
            // found
            if(data == current->data)
            {
                return current; //current node
            }
            //move next
            current = current->next;
        }
        return NULL;
    }
public:

    void add(int data);  // O(1)
    void display();
    bool Search(int data);
    void deleteNode(int data);
    void insertAfter (int afterData,int data);
    void insertBefore (int insertBefore,int data);
    int CountElement();
    int getDataByIndex(int data);
    void ReverseElement();
    LinkedList* reversedListNew();
};

//-----------------------------------
//-----------------------------------

///ADD
void LinkedList::add(int data)
{
    Node* nodeNew = new Node(data);

    if (Head == NULL)
    {
        Head = Tail = nodeNew;
    }
    else
    {
        nodeNew->prev = Tail;
        Tail->next = nodeNew;
        Tail = nodeNew;
    }
}

//-----------------------------------
//-----------------------------------

///Display
void LinkedList::display()
{
    Node* current = Head;
    cout << "Display: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

}

//-----------------------------------
//-----------------------------------

///Search
bool LinkedList :: Search(int data)
{
    if(getNode(data) != NULL)
    {
        return true;
    }
    else
        return false;
}

//-----------------------------------
//-----------------------------------

///Delete
void LinkedList :: deleteNode(int data)
{
    //search
    Node* node = getNode(data);
    if(node != NULL)
    {
        //one element
        if(Head == node && Tail ==node)
        {
            Head = Tail = NULL;
        }
        else if (node == Head)
        {
            Head = node->next;
            Head->prev = NULL;
        }
        else if(node == Tail)
        {
            Tail = node->prev;
            Tail->next = NULL;
        }
        else
        {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
        delete node;
    }
    else
        cout<<"Node Not found.."<<endl;
}

//-----------------------------------
//-----------------------------------
///insertAfter
void LinkedList :: insertAfter (int afterData,int data)
{
    ///search
    Node * node = getNode(afterData);
    if(node == NULL)
        return;

    Node* newNode = new Node(data);
    if(Tail == node)
    {
        //last node -> newNode
        node->next = newNode;
        newNode->prev = node;
        Tail = newNode;
        //newNode->next = NULL;
        return;
    }

    //Normal insert
    newNode->next = node->next;
    newNode->prev = node;

    node->next->prev = newNode; //Go to the next node and stand on the PRV and point to the new node that will be before it.
    node->next = newNode;
}
//-----------------------------------
//-----------------------------------
/// insertBefore
void LinkedList :: insertBefore (int insertBefore,int data)
{
    ///search
    Node * node = getNode(insertBefore);
    if(node == NULL)
        return;

    Node* newNode = new Node(data);
    if(Head == node)
    {
        //first node -> newNode
        newNode->next = node;
        node->prev = newNode;
        Head = newNode;
        newNode->prev = NULL;
        return;
    }

    //Normal insert
    newNode->next = node;
    newNode->prev = node->prev;

    node->prev->next = newNode; //Go to the next node and stand on the PRV and point to the new node that will be before it.
    node->prev  = newNode;
}

//-----------------------------------
//-----------------------------------
///int count()
int LinkedList :: CountElement()
{
    Node * current = Head;
    // Loop
    int CountEle=0;
    while(current != NULL)
    {
        CountEle++;
        //move next
        current = current->next;
    }
    return CountEle;
}

//-----------------------------------
//-----------------------------------
///int Index()
int LinkedList :: getDataByIndex(int data)
{
    int IndexEle=0;
    Node * current = Head;

    while(current != NULL)
    {
        if(current->data == data)
        {
            cout << "Index Element "<<data<<" : " << IndexEle << endl;
            return IndexEle;
        }
        current = current->next;  // move to next node
        IndexEle++;
    }
    cout << "Element not found!" << endl;
    return -1;
}

//-----------------------------------
//-----------------------------------
///ReverseElement
void LinkedList :: ReverseElement()
{
    Node* temp;
    Node* current = Head;
    temp = Head;
    Head = Tail;
    Tail = temp;

    while(current)
    {
        temp = current->next;
        current->next = current->prev;
        current->prev=temp;
        current = current->prev;
    }
}

//-----------------------------------
//-----------------------------------
/// reversedListNew
LinkedList* LinkedList::reversedListNew()
{
    LinkedList* reversedListNew = new LinkedList();
    Node* current = Tail;
    while(current != NULL)
    {
        reversedListNew->add(current->data);
        current = current->prev;
    }

    return reversedListNew;

}

//-----------------------------------
//-----------------------------------
#endif // LINKEDLIST_H
