//**************************************************************************************
//* This program contains the implementation of all of the methods declared for the    *
//* linkedList class template, including those methods created for the class           *
//* LinkedListIterator. This classes will iherit some methods to the class             *
//* unorderedLinkedList                                                                *
//**************************************************************************************

#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>
#include "nodeType.h"
#include "linkedListIterator.h"

using namespace std;

//*****************  class LinkedListType   ****************

template <class Type>
class LinkedListType {
public:
    //Default constructor
    //Initializes the list to an empty state.
    //Postcondition: first = nullptr, last = nullptr,
    //               count = 0;
    LinkedListType();
    
    //copy constructor
    LinkedListType(const LinkedListType<Type>& otherList);

    //Destructor
    //Deletes all the nodes from the list.
    //Postcondition: The list object is destroyed.
    virtual ~LinkedListType();    
    
    //Initialize the list to an empty state.
    //Postcondition: first = nullptr, last = nullptr,
    //               count = 0;
    void initializeList();

    //Function to determine whether the list is empty.
    //Postcondition: Returns true if the list is empty,
    //               otherwise it returns false.
    bool isEmptyList() const;
    
    //Function to output the data contained in each node.
    //Postcondition: none
    void print() const;
    
    //Function to return the number of nodes in the list.
    //Postcondition: The value of count is returned.
    int length() const;
    
    //Function to delete all the nodes from the list.
    //Postcondition: first = nullptr, last = nullptr,
    //               count = 0;
    void destroyList();
    
    //Function to return the first element of the list.
    //Precondition: The list must exist and must not be
    //              empty.
    //Postcondition: If the list is empty, the program
    //               terminates; otherwise, the first
    //               element of the list is returned.
    Type front() const;
    
    //Function to return the last element of the list.
    //Precondition: The list must exist and must not be
    //              empty.
    //Postcondition: If the list is empty, the program
    //               terminates; otherwise, the last
    //               element of the list is returned.
    Type back() const;
    
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the
    //               list, otherwise the value false is
    //               returned.
    virtual bool search(const Type& searchItem) const = 0;
    
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //               inserted at the beginning of the list,
    //               last points to the last node in the list,
    //               and count is incremented by 1.
    virtual void insertFirst(const Type& newItem) = 0;
    
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem
    //               is inserted at the end of the list,
    //               last points to the last node in the
    //               list, and count is incremented by 1.
    virtual void insertLast(const Type& newItem) = 0;
    
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing
    //               deleteItem is deleted from the list.
    //               first points to the first node, last
    //               points to the last node of the updated
    //               list, and count is decremented by 1.
    virtual void deleteNode(const Type& deleteItem) = 0;
    
    //Function to return an iterator at the begining of
    //the linked list.
    //Postcondition: Returns an iterator such that current
    //               is set to first.
    LinkedListIterator<Type> begin() const;
    
    //Function to return an iterator one element past the
    //last element of the linked list.
    //Postcondition: Returns an iterator such that current
    //               is set to nullptr.
    LinkedListIterator<Type> end();
    
    //Overload the assignment operator.
    const LinkedListType<Type>& operator=(const LinkedListType<Type>&);    

private:

    //Function to make a copy of otherList.
    //Postcondition: A copy of otherList is created and
    //               assigned to this list.
    void copyList(const LinkedListType<Type>& otherList);

protected:
    int count;                  //variable to store the number of elements in the list
    NodeType<Type>* top;        //pointer to the first node of the list
    NodeType<Type>* bottom;     //pointer to the last node of the list
};



template <class Type>
LinkedListType<Type>::~LinkedListType() {
    destroyList();
}//end destructor

template <class Type>LinkedListType<Type>::LinkedListType() {
    top = nullptr;
    bottom = nullptr;
    count = 0;
}

template <class Type>
LinkedListType<Type>::LinkedListType(const LinkedListType<Type>& otherList) {
    top = nullptr;
    bottom = nullptr;
    count = 0;
    copyList(otherList);
}//end copy constructor

template <class Type>
bool LinkedListType<Type>::isEmptyList() const {
    return (top == nullptr);
}

template <class Type>
void LinkedListType<Type>::destroyList() {
    NodeType<Type> *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (top != nullptr)   //while there are nodes in
    {                          //the list
        temp = top;        //set temp to the current node
        top = top->next; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }
    bottom = nullptr; //initialize last to nullptr; first has
               //already been set to nullptr by the while loop
    count = 0;
}

template <class Type>
void LinkedListType<Type>::initializeList() {
    destroyList(); //if the list has any nodes, delete them
}

template <class Type>
void LinkedListType<Type>::print() const {
    NodeType<Type> *current; //pointer to traverse the list

    current = top;    //set current so that it points to
                        //the first node
    while (current != nullptr) //while more data to print
    {
        cout << current->info << endl;
        current = current->next;
    }
}//end print

template <class Type>
int LinkedListType<Type>::length() const {
    return count;
}  //end length

template <class Type>
Type LinkedListType<Type>::front() const {
    assert(top != nullptr);

    return top->info; //return the info of the first node
}//end front

template <class Type>
Type LinkedListType<Type>::back() const {
    assert(bottom != nullptr);

    return bottom->info; //return the info of the last node
}//end back

template <class Type>LinkedListIterator<Type> LinkedListType<Type>::begin() const {
    LinkedListIterator<Type> temp(top);

    return temp;
}

template <class Type>LinkedListIterator<Type> LinkedListType<Type>::end() {
    LinkedListIterator<Type> temp(nullptr);

    return temp;
}

template <class Type>
void LinkedListType<Type>::copyList(const LinkedListType<Type>& otherList) {
    NodeType<Type> *newNode; //pointer to create a node
    NodeType<Type> *current; //pointer to traverse the list

    if (top != nullptr) //if the list is nonempty, make it empty
       destroyList();

    if (otherList.top == nullptr) //otherList is empty
    {
        top = nullptr;
        bottom = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.top;   //current points to the
                                   //list to be copied
        count = otherList.count;

            //copy the first node
        top = new NodeType<Type>;  //create the node

        top->info = current->info; //copy the info
        top->next = nullptr;        //set the link field of
                                   //the node to nullptr
        bottom = top;              //make last point to the
                                   //first node
        current = current->next;     //make current point to
                                     //the next node

           //copy the remaining list
        while (current != nullptr)
        {
            newNode = new NodeType<Type>;  //create a node
            newNode->info = current->info; //copy the info
            newNode->next = nullptr;       //set the link of
                                        //newNode to nullptr
            bottom->next = newNode;  //attach newNode after last
            bottom = newNode;        //make last point to
                                   //the actual last node
            current = current->next;   //make current point
                                       //to the next node
        }//end while
    }//end else
}//end copyList

         //overload the assignment operator
template <class Type>
const LinkedListType<Type>& LinkedListType<Type>::operator=(const LinkedListType<Type>& otherList) {
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else

     return *this;
}

#endif
