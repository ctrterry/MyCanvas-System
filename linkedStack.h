//Header File: linkedStack.h
  
#ifndef H_StackType
#define H_StackType
 
#include <iostream> 
#include <cassert>
#include "stackADT.h"
#include "nodeType.h"

using namespace std;
 
template <class Type>
class LinkedStackType: public StackADT<Type> {
public:
 
    //Default constructor
    LinkedStackType();

    //Postcondition: stackTop = nullptr;
    //Copy constructor
    LinkedStackType(const LinkedStackType<Type>& otherStack);    

    
    //Destructor
    //Postcondition: All the elements of the stack are 
    //               removed from the stack.
    ~LinkedStackType();
    
    //Function to determine whether the stack is empty.
    //Postcondition: Returns true if the stack is empty;
    //               otherwise returns false.
    bool isEmptyStack() const;
    
    //Function to determine whether the stack is full.
    //Postcondition: Returns false.
    bool isFullStack() const;
    
    //Function to initialize the stack to an empty state. 
    //Postcondition: The stack elements are removed; 
    //               stackTop = nullptr;
    void initializeStack();
    
    //Function to add newItem to the stack.
    //Precondition: The stack exists and is not full.
    //Postcondition: The stack is changed and newItem 
    //               is added to the top of the stack.
    void push(const Type& newItem);
    
    //Function to return the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: If the stack is empty, the program 
    //               terminates; otherwise, the top 
    //               element of the stack is returned.
    Type& top() const;
   
    //Function to remove the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: The stack is changed and the top 
    //               element is removed from the stack.
    void pop();

    bool operator==(const LinkedStackType<Type>& otherStack) const;

    //Overload the assignment operator.
    const LinkedStackType<Type>& operator= (const LinkedStackType<Type>&);    


protected:
    int count;
    NodeType<Type> *stackTop; //pointer to the stack

    
    //Function to make a copy of otherStack.
    //Postcondition: A copy of otherStack is created and
    //               assigned to this stack.
    void copyStack(const LinkedStackType<Type>& otherStack); 

 
};

template <class Type>
LinkedStackType<Type>::LinkedStackType() {
    count = 0;
    stackTop = nullptr;
    initializeStack();
}

//copy constructor
template <class Type>
LinkedStackType<Type>::LinkedStackType(const LinkedStackType<Type>& otherStack) {
    count = 0;
    stackTop = nullptr;
    copyStack(otherStack);
}//end copy constructor

//destructor
template <class Type>
LinkedStackType<Type>::~LinkedStackType() {
    initializeStack();
}//end destructor

template <class Type>
bool LinkedStackType<Type>::isEmptyStack() const
{
    return(stackTop == nullptr);
} //end isEmptyStack

template <class Type>
bool LinkedStackType<Type>:: isFullStack() const {
    return false;
} //end isFullStack

template <class Type>
void LinkedStackType<Type>:: initializeStack() {
    NodeType<Type> *temp; //pointer to delete the node

    while (stackTop != nullptr)  //while there are elements in 
                              //the stack
    {
        temp = stackTop;    //set temp to point to the 
                            //current node
        stackTop = stackTop->next;  //advance stackTop to the
                                    //next node
        delete temp;    //deallocate memory occupied by temp
    }
} //end initializeStack


template <class Type>
void LinkedStackType<Type>::push(const Type& newElement) {
    NodeType<Type> *newNode;  //pointer to create the new node

    newNode = new NodeType<Type>; //create the node

    newNode->info = newElement; //store newElement in the node
    newNode->next = stackTop; //insert newNode before stackTop
    stackTop = newNode;       //set stackTop to point to the 
                              //top node
    count++;                    // count how items in the stack
} //end push


template <class Type>
Type& LinkedStackType<Type>::top() const {
    assert(stackTop != nullptr); //if stack is empty,
                              //terminate the program
    return stackTop->info;    //return the top element 
}//end top

template <class Type>
void LinkedStackType<Type>::pop() {
    NodeType<Type> *temp;   //pointer to deallocate memory

    if (stackTop != nullptr)
    {
        temp = stackTop;  //set temp to point to the top node

        stackTop = stackTop->next;  //advance stackTop to the 
                                    //next node
        delete temp;    //delete the top node
        count--;
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type> 
void LinkedStackType<Type>::copyStack(const LinkedStackType<Type>& otherStack) {
    NodeType<Type> *newNode, *current, *last;

    if (stackTop != nullptr) //if stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == nullptr)
        stackTop = nullptr;
    else
    {
        current = otherStack.stackTop;  //set current to point
                                   //to the stack to be copied

            //copy the stackTop element of the stack 
        stackTop = new NodeType<Type>;  //create the node

        stackTop->info = current->info; //copy the info
        stackTop->next = nullptr;  //set the link field of the
                                //node to nullptr
        last = stackTop;        //set last to point to the node
        current = current->next;    //set current to point to
                                    //the next node

            //copy the remaining stack
        while (current != nullptr)
        {
            newNode = new NodeType<Type>;

            newNode->info = current->info;
            newNode->next = nullptr;
            last->next = newNode;
            last = newNode;
            current = current->next;
        }//end while
    }//end else
} //end copyStack

//overloading the assignment operator
template <class Type>   
const LinkedStackType<Type>& LinkedStackType<Type>::operator=
        (const LinkedStackType<Type>& otherStack) { 
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this; 
}//end operator=

template <class Type>
bool LinkedStackType<Type>::operator==
        (const LinkedStackType<Type>& otherStack) const {
    NodeType<Type> *current1 = stackTop;
    NodeType<Type> *current2 = otherStack.stackTop;

    if (this == &otherStack)
        return true;
    else
    {
        while (current1 != nullptr && current2 != nullptr)
        {
            if (current1->info != current2->info)
                return false;

            current1 = current1->next;
            current2 = current2->next;
        }

        if (current1 != nullptr || current2 != nullptr)
            return false;

        return true;
    }
}

#endif
