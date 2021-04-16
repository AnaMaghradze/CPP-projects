#include "platypus.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#include "platypus.h"

int main(){

    srand(time(0));
    cout<<"\n\t<< Welcome To Mr. Burns' Newfangled Computer Simulations >>\n";
    cout<<"\t\t Here You Will Meet Little Platypuses\n\n";
    cout<<"\t\t Press << Y >> If You Want To See Them \n";
    cout<<"\t\t Press << N >> If You Want To Exit ";
    char ch1;
    B:
    cin>>ch1;
    if(ch1 == 'y' || ch1 == 'Y'){
    cout<< "\n   __________________________________________________________________________ \n\n";
    }
    else if(ch1 == 'n' || ch1 == 'N'){
        cout<< "\n\n\t\t\t\t<< BYE >> \n\n\n\n";
        return 0;
    }
    else{
        cout<< "\n\t Please, Enter Valid Input\n";
        goto B;
    }
    cout<< "\tThis Is Your platypus: \n\n";
    platypus p('k', 'M', 12, 5.0);
    p.print(cout);

    platypus p1;  // object p1
    platypus p2;  // object p2

cout<<"\n\tDo You Want To See The Platypus After Several Months? << Y >> << N >>";  // for age_me function
    char cho;
    A:
    cin>>cho;
    if(cho == 'y' || cho == 'Y'){
        cout<< "\n\n\tLet's Observe... \n\n";
        p.age_me();
        p.print(cout);
    }
    else if(cho == 'n' || cho == 'N'){
        cout<< "\n\n";
    }
    else{
        cout<< "\n\t Please, Enter Valid Input...";
        goto A;
    }

cout<<"\n\tDo You Want To Feed The Platypus? << Y >>  << N >>";        // for eat function
    char option;
    C:
    cin>>option;
    if(option == 'y' || option == 'Y')
    {
        cout<< "\n\tLet's Observe...\n\n";
        D:
        p.eat();
        p.print(cout);
        if(p.getWeight()>= 10)
                {
                  cout<< "\n";
                  cout<< "\n\tHowever, You Can See A Newborn Platypus. \n"<<endl;
                  goto F;
                }
        cout<<"\tDo You Want To Feed It Again? << Y >>  << N >>";        // to continue feeding
        E:
        char ch3;
        cin>>ch3;
        if(ch3 == 'y' || ch3 == 'Y'){
                goto D;}
        else if(ch3 == 'n' || ch3 == 'N'){
            cout <<"\n\n";}
        else{
            cout<< "\n\t Please, Enter Valid Input...";
            goto E;}
    }
    else if(option== 'n' || option == 'N')
    {cout <<"\n";}
    else{
        cout<< "\n\t Please, Enter Valid Input...";
        goto C;
    }

cout <<"\tDo You Want To Make Two Platypuses Fight Each Other? << Y >> << N >> \n\n\n";   // for fight function
    char opt;
    cin>>opt;
        if(opt == 'y' || opt == 'Y'){
            cout<< "\tYou Can Chose The Opponent...\n\n";
            char enemyName;
            int enemyAge;
            char enemyGen;
            float enemyWeight;
            K:
            cout<< "\tEnter The Name Of The Opponent: ";
            while(!(cin>>enemyName))
            {
                cout<< "\t  Please, Choose A Letter From Alphabet...\n";
                cin.clear();
                cin.ignore(50,'\n');
                goto K;
            }
            L:
            cout<< "\tEnter The Age Of The Opponent: \n";
            while(!(cin>>enemyAge))
            {
                cout<< "\t  Please, Enter A Number...\n";
                cin.clear();
                cin.ignore(50,'\n');
                goto L;
            }
            M:
            cout<< "\tEnter The Gender Of The Opponent: \n";
            cin>>enemyGen;
            if(!((enemyGen == 'm') || (enemyGen == 'M') || (enemyGen == 'f') || (enemyGen == 'F'))) // check for gender input
            {
               cout<< "\t  Please, Enter < M > For Male, or < F > For Female Platypus...\n";
               goto M;
            }
            N:
            cout<< "\tEnter The Weight Of The Opponent: \n";
            while(!(cin>>enemyWeight))
            {
                cout<< "\t  Please, Enter A Number...\n";
                cin.clear();
                cin.ignore(50,'\n');
                goto N;
            }
            cout<<"\n";
            p2.setName(enemyName);
            p2.setAge(enemyAge);
            p2.setGender(enemyGen);
            p2.setWeight(enemyWeight);
            p2.setAlive(1);
            p2.setMutant(0);
            p2.print(cout);
            cout<< "Let's See The Results of Battle...\n";
            p.fight(p2);
            p.print(cout);
            p2.print(cout);
        }
        if(opt == 'n' || opt == 'N'){
            cout <<"\n";
            }

F:
cout<< "\tDo You Want To See A Newborn Platypus? << Y >>  << N >>\n\n\n";   // for hatch function
    char op;
    cin>>op;
        if(op == 'y' || op == 'Y'){
            p1.hatch();
            p1.print(cout);
        }
        else if(op == 'n' || op == 'N'){
            cout <<"\n";
        }
        else{
            cout<< "\n\t Please, Enter Valid Input...\n";
            goto F;
        }

    cout<<"\t\t\t  << That's ALL >>";
    cout<< "\n\n\t\t\t      << BYE >> \n\n\n\n";
    return 0;
}
