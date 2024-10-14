#ifndef H_linkedQueue
#define H_linkedQueue 
 
#include <iostream>
#include <cassert>
#include "queueADT.h"
#include "nodeType.h"

using namespace std;

template<class Type>
class LinkedQueueType: public QueueADT<Type> {
public:  
    LinkedQueueType();

    //Copy constructor
    LinkedQueueType(const LinkedQueueType<Type>& otherQueue);

    //Destructor
    virtual ~LinkedQueueType();

    //Overload the assignment operator.
    const LinkedQueueType<Type>& operator=
                (const LinkedQueueType<Type>&); 
    
    //Function to determine whether the queue is empty. 
    //Postcondition: Returns true if the queue is empty,
    //               otherwise returns false.
    bool isEmptyQueue() const;
    
    //Function to determine whether the queue is full. 
    //Postcondition: Returns true if the queue is full,
    //               otherwise returns false.
    bool isFullQueue() const;
    
    //Function to initialize the queue to an empty state.
    //Postcondition: queueFront = nullptr; queueRear = nullptr
    void initializeQueue();
    
    //Function to return the first element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: If the queue is empty, the program 
    //               terminates; otherwise, the first 
    //               element of the queue is returned. 
    Type& front() const;
    
    //Function to return the last element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: If the queue is empty, the program 
    //               terminates; otherwise, the last 
    //               element of the queue is returned.
    Type back() const;
   
    //Function to add queueElement to the queue.
    //Precondition: The queue exists and is not full.
    //Postcondition: The queue is changed and queueElement
    //               is added to the queue.
    void addQueue(const Type& queueElement);
    
    //Function  to remove the first element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: The queue is changed and the first 
    //               element is removed from the queue.
    void deleteQueue();
   
    int getCount() const {return count;};



private:
    NodeType<Type> *queueFront; //pointer to the front of 
                                //the queue
    NodeType<Type> *queueRear;  //pointer to the rear of 
                                //the queue
    int count; //stores number of elements
};

template<class Type>
LinkedQueueType<Type>::LinkedQueueType() {
    count = 0;
    queueFront = nullptr;
    queueRear = nullptr;
};

//copy constructor
template<class Type>
LinkedQueueType<Type>::LinkedQueueType(
    const LinkedQueueType<Type>& otherQueue)
{
    NodeType<Type>* newNode; //pointer to create a node
    NodeType<Type>* current; //pointer to traverse the list

    if (otherQueue.queueFront == nullptr) //otherList is empty
    {
        queueFront = nullptr;
        queueRear = nullptr;
    }
    else
    {
        current = otherQueue.queueFront;    //current points to the 
        //list to be copied

        //copy the first node
        queueFront = new NodeType<Type>;  //create the node
        queueFront->info = current->info; //copy the info
        queueFront->next = nullptr;    //set the link field of 
        //the node to nullptr
        queueRear = queueFront;     //make rear point to the 
        //front node
        current = current->next;    //make current point to the 
        //next node

        //copy the remaining list
        while (current != nullptr)
        {
            newNode = new NodeType<Type>;   //create a node
            newNode->info = current->info;  //copy the info
            newNode->next = nullptr;       //set the link of 
            //newNode to nullptr
            queueRear->next = newNode;  //attach newNode after rear
            queueRear = newNode;    //make rear point to
            //the actual rear node
            current = current->next;   //make current point to
            //the next node
        }//end while
    }//end else
    count = otherQueue.count;
}//end copy constructor

//Destructor
template<class Type>
LinkedQueueType<Type>::~LinkedQueueType()
{
    NodeType<Type>* temp;

    while (queueFront != nullptr)  //while there are elements 
        //left in the queue
    {
        temp = queueFront;  //set temp to point to the 
        //current node
        queueFront = queueFront->next;  //advance first to 
        //the next node
        delete temp;    //deallocate memory occupied by temp
    }

    queueRear = nullptr;   // set rear to nullptr
} //end destructor

template<class Type>
bool LinkedQueueType<Type>::isEmptyQueue() const
{
    return(queueFront == nullptr);
} //end 

template<class Type>
bool LinkedQueueType<Type>::isFullQueue() const
{
    return false;
} //end isFullQueue

template<class Type>
void LinkedQueueType<Type>::initializeQueue()
{
    NodeType<Type> *temp;

    while(queueFront!= nullptr)  //while there are elements left
                              //in the queue
    {
        temp = queueFront;  //set temp to point to the 
                            //current node
        queueFront = queueFront->next;  //advance first to  
                                        //the next node
        delete temp;    //deallocate memory occupied by temp
    }
    queueRear = nullptr;  //set rear to nullptr
    count = 0;
}  //end initializeQueue

template<class Type>
void LinkedQueueType<Type>::addQueue(const Type& newElement)
{
    NodeType<Type> *newNode;

    newNode = new NodeType<Type>;   //create the node

    newNode->info = newElement; //store the info
    newNode->next = nullptr;  //initialize the link field to nullptr
	
    if (queueFront == nullptr) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else        //add newNode at the end
    {
        queueRear->next = newNode;
        queueRear = queueRear->next;
    }
    count++;
}//end addQueue

template<class Type>
Type& LinkedQueueType<Type>::front() const //***changed by me
{
    assert(queueFront != nullptr);
    return queueFront->info; 
} //end front

template<class Type>
Type LinkedQueueType<Type>::back() const
{
    assert(queueRear!= nullptr);
    return queueRear->info;
} //end back

template<class Type>
void LinkedQueueType<Type>::deleteQueue()
{
    NodeType<Type> *temp;
   
    if (!isEmptyQueue())
    {
        temp = queueFront;  //make temp point to the 
                            //first node
        queueFront = queueFront->next; //advance queueFront 
        delete temp;    //delete the first node

        if (queueFront == nullptr) //if after deletion the 
                                //queue is empty
            queueRear = nullptr;   //set queueRear to nullptr
        count--;
    }
    else
        cerr << "Cannot remove from an empty queue" << endl;

}//end deleteQueue

template<class Type>
const LinkedQueueType<Type>& LinkedQueueType<Type>::operator=
								(const LinkedQueueType<Type>& otherQueue)
{
    NodeType<Type> *newNode; //pointer to create a node
    NodeType<Type> *current; //pointer to traverse the list.
     
    if (this != &otherQueue) //avoid self-copy
    {
        if (queueFront != nullptr)  //if the list is not empty, destroy the list
            initializeQueue();

        if (otherQueue.queueFront == nullptr) //otherList is empty
        {
            queueFront = nullptr;
            queueRear = nullptr;
        }	
        else
        {
            current = otherQueue.queueFront;	//current points to the 
                                                //list to be copied

                //copy the front element
            queueFront = new NodeType<Type>;    //create the node
            queueFront->info = current->info;   //copy the info
            queueFront->next = nullptr;    //set the link field of
                                        //the node to nullptr
            queueRear = queueFront;     //make rear point to the first node
            current = current->next;    //make current point to the next
  		  							    //node of the list being copied

                //copy the remaining list
            while (current != nullptr)
            {
                newNode = new NodeType<Type>;
                newNode->info = current->info;
                newNode->next = nullptr;
                queueRear->next = newNode;
                queueRear = newNode;
                current = current->next;
            }//end while
        }//end else
    }//end else

    count = otherQueue.count;
    return *this; 
} //end assignment operator

#endif
