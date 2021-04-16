#ifndef STAQUE_H
#define STAQUE_H

#include <stdio.h>
#include <iostream>
using namespace std;

typedef int ElementType;    // type of integer

class Staque
{
    public:
        Staque();                           // default constructor
        Staque(const Staque & origList);    // copy constructor
        ~Staque();                          // destructor

        const Staque & operator= (const Staque & rightHandSide);    // assignment operator

        bool empty() const;        // empty
        void push(int num);       // if even - in front of the Staque, if odd - at the end of the Staque
        void pop();                // for removal based on LIFO
        void display(ostream & out) const;   // to display the Staque
        ElementType frontValue() const;      // for front part
        ElementType backValue() const;       // for back part

    private:
        class Node
        {
        public:
            ElementType myData;
            ElementType position;
            Node *nextNode;
            Node *previousNode;
            // constructor for Node
            Node(ElementType number, ElementType counter, Node *frontPart = 0, Node *backPart = 0)
                 : myData(number), position(counter), nextNode(frontPart), previousNode(backPart) {}
        };

        typedef Node *nodePtr;

        nodePtr myFront;            // pointer to first
        nodePtr myEnd;              // pointer to last
        ElementType termCounter;    // to count items
};
#endif // STAQUE_H
