//**************************************************************************************
//* Name: linked lists                                                                 *
//* Description:                                                                       *
//* This program contains the declaration and implementation of all of the methods     *
//* declared for the template class UnorderedLinkedList. This class also inherits      *
//* some methods declared and implemented in LinkedListType                            *
//* UnorderedLinkedList                                                                *
//**************************************************************************************
#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"

using namespace std;

template <class Type>
class UnorderedLinkedList:public LinkedListType<Type> {
public:
    
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the
    //               list, otherwise the value false is
    //               returned.
    bool search(const Type& searchItem) const;
    Type& searchBy(const Type& searchItem) const;
    
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //               inserted at the beginning of the list,
    //               last points to the last node in the
    //               list, and count is incremented by 1.
    void insertFirst(const Type& newItem);

    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem
    //               is inserted at the end of the list,
    //               last points to the last node in the
    //               list, and count is incremented by 1.
    void insertLast(const Type& newItem);      
   
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing
    //               deleteItem is deleted from the list.
    //               first points to the first node, last
    //               points to the last node of the updated
    //               list, and count is decremented by 1.
    void deleteNode(const Type& deleteItem);
};


template <class Type>
bool UnorderedLinkedList<Type>::search(const Type& searchItem) const {
    NodeType<Type> *current; //pointer to traverse the list
    bool found = false;

    current = this->top; //set current to point to the first
                     //node in the list

    while (current != nullptr && !found)    //search the list
        if (current->info == searchItem) { //searchItem is found
            found = true;
        }
        else
            current = current->next; //make current point to
                                     //the next node
    return found;
}//end search

template <class Type>
Type& UnorderedLinkedList<Type>::searchBy(const Type& searchItem) const {
    NodeType<Type>* current; //pointer to traverse the list
    bool found = false;

    current = this->top; //set current to point to the first
    //node in the list

    while (current != nullptr && !found)    //search the list
        if (current->info == searchItem) { //searchItem is found
            found = true;
            return current->info;
        }
        else
            current = current->next; //make current point to
    //the next node
    return current->info;
}//end search

template <class Type>
void UnorderedLinkedList<Type>::insertFirst(const Type& newItem) {
    NodeType<Type> *newNode; //pointer to create the new node

    newNode = new NodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->next = this->top;        //insert newNode before first
    this->top = newNode;              //make first point to the
                                //actual first node
    this->count++;                     //increment count

    if (this->bottom == nullptr)    //if the list was empty, newNode is also
                        //the last node in the list
        this->bottom = newNode;
}//end insertFirst

template <class Type>
void UnorderedLinkedList<Type>::insertLast(const Type& newItem) {
    NodeType<Type> *newNode; //pointer to create the new node

    newNode = new NodeType<Type>; //create the new node

    newNode->info = newItem;  //store the new item in the node
    newNode->next = nullptr;     //set the link field of newNode
                              //to nullptr

    if (this->top == nullptr)  //if the list is empty, newNode is
                        //both the first and last node
    {
        this->top = newNode;
        this->bottom = newNode;
        this->count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        this->bottom->next = newNode; //insert newNode after last
        this->bottom = newNode; //make last point to the actual
                        //last node in the list
        this->count++;        //increment count
    }
}//end insertLast


template <class Type>
void UnorderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
    NodeType<Type> *current; //pointer to traverse the list
    NodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (this->top == nullptr)    //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (this->top->info == deleteItem) //Case 2
        {
            current = this->top;
            this->top = this->top->next;
            this->count--;
            if (this->top == nullptr)    //the list has only one node
                this->bottom = nullptr;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = this->top;  //set trailCurrent to point
                                   //to the first node
            current = this->top->next; //set current to point to
                                   //the second node

            while (current != nullptr && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->next;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->next = current->next;
                this->count--;

                if (this->bottom == current)   //node to be deleted
                                       //was the last node
                    this->bottom = trailCurrent; //update the value
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode


#endif
