#ifndef H_UnorderedArrayListType
#define H_UnorderedArrayListType
  
#include <iostream>
#include "ArrayListType.h"
#include "searchSortAlgorithms.h"

using namespace std; 

template <class elemType>
class UnorderedArrayListType: public ArrayListType<elemType>
{
public:
    //Constructor
    UnorderedArrayListType(int size = 100);

    void insertAt(int location, const elemType& insertItem);
    void insertEnd(const elemType& insertItem);
    void replaceAt(int location, const elemType& repItem);    
    void remove(const elemType& removeItem);    
    int seqSearch(const elemType& searchItem) const;

    void sort(bool ascending);
    void sortASC();
    void sortDESC();
    int search(elemType& searchItem);
};  

template <class elemType>
void UnorderedArrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
    // May be override to insert at
    insertEnd(insertItem);
} //end insertAt

template <class elemType>
void UnorderedArrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    if (this->length >= this->maxSize)  //the list is full
        cout << "Cannot insert in a full list." << endl;
    else
    {
        this->list[this->length] = insertItem; //insert the item at the end
        this->length++; //increment the length
    }
} //end insertEnd

template <class elemType>
int UnorderedArrayListType<elemType>::seqSearch(const elemType& searchItem) const
{
    int loc;
    bool found = false;
    loc = 0;

    while (loc < this->length && !found)
        if (this->list[loc] == searchItem)
            found = true;
        else
            loc++;

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
void UnorderedArrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;

    if (this->length == 0)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            this->removeAt(loc);
        else
            cout << "The tem to be deleted is not in the list."
                 << endl;
    }
} //end remove

template <class elemType>
void UnorderedArrayListType<elemType>::replaceAt(int location, const elemType& repItem)
{
    if (location < 0 || location >= this->length)
        cout << "The location of the item to be "
             << "replaced is out of range." << endl;
    else
        this->list[location] = repItem;
} //end replaceAt

template <class elemType>
UnorderedArrayListType<elemType>::UnorderedArrayListType(int size)
    : ArrayListType<elemType>(size)
{
}  //end constructor

template <class elemType>
void UnorderedArrayListType<elemType>::sort(bool ascending) {
    if (ascending) {
        sortASC();
    }
    else {
        sortDESC();
    }
} 

// sort in ascending order
template <class elemType>
void UnorderedArrayListType<elemType>::sortASC() {
    selectionSort(this->list, this->listSize(), true);
}
// Sort in descending order
template <class elemType>
void UnorderedArrayListType<elemType>::sortDESC() {
    // Sort descending...
    selectionSort(this->list, this->listSize(), false);

}
template <class elemType>
int UnorderedArrayListType<elemType>::search(elemType& searchItem) {
    return binarySearch(this->list, this->listSize(), searchItem);
}

#endif