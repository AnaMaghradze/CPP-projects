#include "platypus.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

platypus::platypus () // Default Constructor For Dead Platypus
{
    alive = false;
    mutant = false;
}
platypus::platypus(char name, char gender, short age, float weight) // explicit-value constructor
{
    this->name = name;
    this->gender = gender;
    this->age= age;
    this->weight = weight;
    this->alive = true;
    this->mutant = false;
}
void platypus::age_me(){    // Age function for Object's Age
    if(alive==1){
    cout<< "\tPlease, Enter The Number Of Months: ";
    A:
    int month, mutationRisk = 0;
    while(!(cin>>month)){
        cin.clear();
        cin.ignore(50,'\n');
        cout<< "\tPlease, Enter Valid Input.\n";
        goto A;
    }
    cout<<"\n\nAter "<<month<<" Months: \n\n";

    for(int i=0; i<month; i++){
        age++;
        mutationRisk = 2*(1+0.01*2*age);   // mutation risk increases by 2% a month
        }

    cout<<"\t"<<mutationRisk<< "% chance of Mutation"<<endl;
    if(mutationRisk < 100){
        setMutant(0);}
    else{ setMutant(1);}
    }
    short deathRisk = (short)weight*10;   // death risk is 10 times object's weight
    if(deathRisk > 100){
        cout<< "\tThe Platypus Cannot Eat Anymore, It's Dead..."<<endl;    // dead platypus cannot eat
    }
    else{
        cout<<"\t"<<deathRisk<< "% chance of dying"<<endl;}
}

void platypus::eat(){                                       // eat function to feed the platypus
    float increase = getWeight()*(rand()%50+1)/1000.0;      // random number between 0.1-5.0% of weight
    if(alive==true){
    setWeight(getWeight()+increase);
        if(getWeight()>=10){
            cout<< "\n\tOops...\n"<<endl;
            cout<< "\tThe Platypus Cannot Eat Anymore, It's Dead..."<<endl;
            cout<< "\tIt Cannot Fight As Well..."<<endl;
            setAlive(0);
        }
        else{cout<< "\tThe Platypus Is Fattened And Fattened...\n\n";}
    }
}

void platypus::print(ostream & out)
{
    out << "\tNAME:       " << name << endl;
    out << "\tGENDER:     " << gender << endl;
    out << "\tAGE:        " << age <<" Months"<< endl;
    out << "\tWEIGHT:     " << weight <<" Pounds"<< endl;

    if(alive){
        cout << "\tALIVE:      Yes"<<endl;}
    else {
        cout << "\tALIVE:      No"<<endl;}
    if(mutant) {
        cout << "\tMUTANT:     Yes"<<endl;}
    else {
        cout << "\tMUTANT:     No"<<endl;}
    cout << endl;
}

ostream & operator<<(ostream & out, platypus & p)   //  to overload operator <<
{
  p.print(out);
  return out;
}

void platypus::fight(platypus & other)                  // fight function
{
    float weightRatio = (this->weight/other.getWeight())*50;
    short rendomizing = rand()%100;

    if(!(this->alive && other.alive))
    {
        cout<< "Platypuses Cannot fight, One Of Them (Or Both) Is Dead."<<endl;
    }
    else{
        if(rendomizing<weightRatio){
            cout<<"\n\t"<<this->name<<" Survived\n"<<endl;
            other.setAlive(0);
        }
        else{
            cout<<"\n\t"<<other.getName()<< " Survived\n"<<endl;
            this->alive = false;
        }
    }
}
void platypus::hatch(){
    bool newborn_alive = true;                   // alive
    bool newborn_mutant = false;                 // mutant
    short newborn_age = 0;                       // age
    float newborn_weight = (rand()%10+1)/10.0;   // weight
    int genderRand = rand()%2;                   // gender
    if(genderRand == 1)
        {gender = 'M';}
    else{gender = 'F';}

    char newborn_name=('a' + rand()%26);
    if(genderRand == 1){
        cout<< "\tThe Baby Platypus Is Female, So What Name Do You Want To Give It? " << endl;
        char userName_f;
        B:
        while(!(cin>>userName_f))
        {
            cout<< "\tPlease, Choose A Letter From Alphabet...";
            cin.clear();
            cin.ignore(50,'\n');
            goto B;
        }
        newborn_name = userName_f;
        }
    else{
        cout<< "\tThe Baby Platypus Is Male, So What Name Do You Want To Give It? "<< endl;
        char userName_m;
        C:
        while(!(cin>>userName_m))
        {
            cout<< "\tPlease, Choose A Letter From Alphabet...";
            cin.clear();
            cin.ignore(50,'\n');
            goto C;
        }
        newborn_name = userName_m;
        }
    cout<< "\n\tThis Is A Newborn Platypus \n";
    setAlive(newborn_alive);
    setMutant(newborn_mutant);
    setAge(newborn_age);
    setWeight(newborn_weight);
    setName(newborn_name);
}
    // definition of accessors
    char platypus::getName() const
    {return name;}
    short platypus::getAge() const
    {return age;}
    float platypus::getWeight() const
    {return weight;}
    char platypus::getGender() const
    {return gender;}
    bool platypus::getAlive()const
    {return alive;}
    bool platypus::getMutant() const
    {return mutant;}
    // definition of mutators
    void platypus::setName(char nameP){this->name = nameP;}
    void platypus::setAge(char ageP){this->age = ageP;}
    void platypus::setWeight(float weightP){this->weight = weightP;}
    void platypus::setGender(char genderP){this->gender = genderP;}
    void platypus::setAlive(bool aliveP){this->alive = aliveP;}
    void platypus::setMutant(bool mutantP){this->mutant = mutantP;}

platypus::~platypus(){} // Destructor
