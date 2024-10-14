#pragma once
#include "nodeType.h"

template <class Type>
class LinkedListIterator {
public:
    //Default constructor
    //Postcondition: current = nullptr;
    LinkedListIterator();    

    //Constructor with a parameter.
    //Postcondition: current = ptr;
    LinkedListIterator(NodeType<Type>* ptr);    

    Type& operator*();
    //Function to overload the dereferencing operator *.
    //Postcondition: Returns the info contained in the node.    

    //Overload the equality operator.
    //Postcondition: Returns true if this iterator is equal to
    //               the iterator specified by right,
    //               otherwise it returns the value false.
    bool operator==(const LinkedListIterator<Type>& right) const;    
    
    //Overload the not equal to operator.
    //Postcondition: Returns true if this iterator is not
    //               equal to the iterator specified by
    //               right; otherwise it returns the value
    //               false.
    bool operator!=(const LinkedListIterator<Type>& right) const;

    //Overload the pre-increment operator.
    //Postcondition: The iterator is advanced to the next
    //               node.
    LinkedListIterator<Type> operator++();    

    LinkedListIterator<Type> operator--(); // TODO

private:
    NodeType<Type>* current; //pointer to point to the current
                             //node in the linked list
};

template <class Type>LinkedListIterator<Type>::LinkedListIterator(){
    current = nullptr;
}

template <class Type>
LinkedListIterator<Type>::LinkedListIterator(NodeType<Type>* ptr) {
    current = ptr;
}

template <class Type>
Type& LinkedListIterator<Type>::operator*(){
    return current->info;
}

template <class Type>
LinkedListIterator<Type> LinkedListIterator<Type>::operator++(){
    current = current->next;
    return *this;
}

template <class Type>
LinkedListIterator<Type> LinkedListIterator<Type>::operator--() {
    // TODO
    current = current->back;
    return *this;
}

template <class Type>
bool LinkedListIterator<Type>::operator==(const LinkedListIterator<Type>& right) const{
    return (current == right.current);
}

template <class Type>
bool LinkedListIterator<Type>::operator!=(const LinkedListIterator<Type>& right) const {
    return (current != right.current);
}

