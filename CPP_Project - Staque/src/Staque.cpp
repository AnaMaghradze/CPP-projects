#include "Staque.h"
#include <new>
using namespace std;

Staque::Staque()                                // definition of constructor
    : myFront(0), myEnd(0), termCounter(0){}

Staque::Staque(const Staque & origList)         // definition of copy constructor
{
    myFront = 0; myEnd = 0; termCounter = 0;
    if(!origList.empty())
    {
        myFront = new Staque::Node(origList.frontValue(), origList.myFront->position); // to copy 1st node
        myEnd = myFront;
        termCounter++;
        // setting pointers
        Staque::nodePtr ptr, ptr_Previous = 0, ptr_Last = myFront;
        ptr = origList.myFront->nextNode;
        ptr_Last->previousNode = 0;
        while(ptr!=0)
        {
            ptr_Last->nextNode = new Staque::Node(ptr->myData, ptr->position);
            ptr_Previous=ptr_Last;
            ptr_Last = ptr_Last->nextNode;
            ptr_Last->previousNode = ptr_Previous;
            ptr = ptr->nextNode;
            ptr_Last->nextNode = 0;
            termCounter++;
        }
    }
}

Staque::~Staque()                       // definition of destructor
{
    Staque::nodePtr current_ptr = myFront, next_ptr;
    while(current_ptr != 0)
    {
        next_ptr = current_ptr->nextNode;
        delete current_ptr;
        current_ptr = next_ptr;
    }
}

const Staque & Staque::operator=(const Staque & rightHandSide)    // assignment operator
{
    if(this != &rightHandSide){
        this->~Staque();                        // to destroy curr list
        if(rightHandSide.empty()){
                myFront = 0;
            }
        else{
            myFront = new Staque::Node(rightHandSide.frontValue(), rightHandSide.myFront->position);
            myEnd = myFront;
            termCounter++;

            Staque::nodePtr ptrR, ptr_Previous = 0, ptr_Last = myFront;
            ptrR = rightHandSide.myFront->nextNode;
            ptr_Last->previousNode = 0;
            while(ptrR!=0)
            {
                ptr_Last->nextNode = new Staque::Node(ptrR->myData, ptrR->position);
                ptr_Previous=ptr_Last;
                ptr_Last = ptr_Last->nextNode;
                ptr_Last->previousNode = ptr_Previous;
                ptrR = ptrR->nextNode;
                ptr_Last->nextNode = 0;
                termCounter++;
            }
        }
    }
    return *this;
}


bool Staque::empty() const          // definition of empty function
{
	return(termCounter == 0);
}

void Staque::push(int userVal)
{
    Staque::nodePtr currentPtr = myFront;
    if(termCounter == 0)                        // inserting first node
    {
        termCounter++;                          // number of nodes is increasing
        myFront = new Staque::Node(userVal, termCounter, myFront, myEnd);
        myEnd = myFront;
    }
    else                                // inserting other nodes
    {
        if(userVal % 2 == 0)            // for even numbers
        {
            termCounter++;              // number of is increasing
            myFront = new Staque::Node(userVal, termCounter, myFront, 0);
            currentPtr->previousNode = myFront;
        }
        else{
           termCounter++;               // for odd numbers
           myEnd->nextNode = new Staque::Node(userVal, termCounter, 0, myEnd);
           myEnd = myEnd->nextNode;   // goes at the end of Staque
        }
    }
}

void Staque::pop()              // definition of pop function
{
    if(!empty())
    {
        Staque::nodePtr temp_ptr;
        if(myFront->position == termCounter)
        {
            temp_ptr = myFront;
            myFront=myFront->nextNode;
            if(myFront!=0){
                myFront->previousNode = 0;
            }
            termCounter--;          // num of nodes is decreasing
            delete temp_ptr;
        }
        else if(myEnd->position == termCounter)
        {
            temp_ptr = myEnd;
            myEnd=myEnd->previousNode;
            myEnd->nextNode = 0;
            termCounter--;
            delete temp_ptr;
        }
        else{
            cout<< "\n   Error... \n";
        }
}
    else {
        cout<< "\n   The Staque Is Empty...\n";
    }
}

void Staque::display(ostream & out) const           // definition of display function
{
    Staque::nodePtr temp_ptr;
    cout<<"\n\t\t";
    for(temp_ptr = myFront; temp_ptr != 0; temp_ptr=temp_ptr->nextNode)
    {
        out<<temp_ptr->myData<<" ";
    }
    cout<<endl;
}

ElementType Staque::frontValue()const
{
    if(!empty()){
        return myFront->myData;     // value in front of the Staque
    }
    else{
        cout<<"\n   The Staque Is Empty."<<endl;
        ElementType *temp_ptr = new(ElementType);
        ElementType garbageVal = *temp_ptr;
        delete temp_ptr;
        return garbageVal;
    }
}

ElementType Staque::backValue()const
{
    if(!empty()){
        return myEnd->myData;   // value at the end of the Staque
    }
    else{
        cout<<"\n   The Staque Is Empty."<<endl;
        ElementType *temp_ptr = new(ElementType);
        ElementType garbageVal = *temp_ptr;
        delete temp_ptr;
        return garbageVal;
    }
}
