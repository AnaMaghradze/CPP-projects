#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#ifndef PLATYPUS_H
#define PLATYPUS_H

class platypus
{
    public:
        platypus(); // for dead platypus
        platypus(char name, char gender, short age, float weight); // explicit-value constructor

        void age_me();                      // To increment object's age
        void eat();                         // To increase object's weight
        void hatch();                       // To create a newborn platypus
        void print(ostream & out);          // To display output on screen
        void fight(platypus & another_p);   // To make platypuses fight
        // accessors
        char getName() const;
        short getAge() const;
        float getWeight() const;
        char getGender() const;
        bool getAlive()const;
        bool getMutant() const;
        //mutators
        void setName(char nameP);
        void setAge(char ageP);
        void setWeight(float weightP);
        void setGender(char genderP);
        void setAlive(bool aliveP);
        void setMutant(bool mutantP);
        // destructor
        virtual ~platypus();

    private:
        char name;
        char gender;
        short age;
        float weight;
        bool alive;
        bool mutant;
};

#endif // PLATYPUS_H
