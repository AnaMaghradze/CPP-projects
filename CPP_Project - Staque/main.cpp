#include "Staque.h"
#include <iostream>
using namespace std;
#include "Staque.h"

void userChoice();
void emptyChecker(Staque & stq);
void printStaque(Staque & stq);

int main()
{
    Staque a;
    bool b = true;

    cout << "\n\t\t\t\tWELCOME!" << endl;
    cout << "\n\t\tHERE WE CREATE AND MODIFY \"STAQUES\"" << endl;
    cout << "\n\t\t  >> You can store integers in Staqe" << endl;
    cout << "\n\t\t  >> Odd Numbers Are Added At The End Of The Staque" << endl;
    cout << "\n\t\t  >> Even Numbers Are Added In Front Of The Staque" << endl;
    cout << "\n\t\t  >> You Can Remove Items From Either The front Or "<< endl;
    cout << "\n\t\t      From The Back Of The Staque (The LIFO Rule)" << endl;
    cout << "\n\t\tIF YOU WANT TO SEE HOW DOES IT WORK, PRESS ";
    userChoice();
    cout << "\n   _______________________________________________________________________";

    do{
    cout << "\n\n   Let's Begin...\n" << endl;
    printStaque(a);
    emptyChecker(a);        // to show there is no items in Staque

    cout<< "\n>> If You Want To Add Items To The Staque, Press ";
    userChoice();

    cout<< ">> How Many Items Do You Want To Add To The Staque? ";
    int n;
    cin>>n;
    cout<< "\n   Please, Enter "<<n<<" Items You Want To Add: ";
    for(int i=0; i<n; i++)
    {
        int item;
        A:
        while(!(cin>>item)){        // to check if the input is integer or not
            cout<< "\n   ! INVALID INPUT, ENTER AN INTEGER ";
            cin.clear();
            cin.ignore(100, '\n');
            goto A;
        }
        a.push(item);
    }
    cout << "\n   Items Are Being Arranged In The Staque...\n" << endl;

	cout << "\n   Let's Check The Staque Again To See Whether It Is Empty Or Not...\n" << endl;
    emptyChecker(a);            // to show how Staque was changed
    if(!a.empty()){
        cout<< "   The Top Item Is: "<<a.frontValue()<<endl;
        cout<< "   The Last Item Is: "<<a.backValue()<<endl;
    }
    printStaque(a);

    if(!a.empty()){         // if Staque is not empty, user can remove items
    cout << "\n\n>> You Can Also Remove Numbers From Staque." << endl;
    cout << "   Number Removal Follows The LIFO Rule." << endl;
    cout << "   So, If You Want To Remove Any Item, Press ";
    userChoice();

    cout << "\n   How Many Items Do You Want To Remove?"<<endl;
    int m;
    cin>>m;
    for(int j=0; j<m; j++){
    a.pop();
    }
    cout << "\n   "<<m<<" Items Were Removed From The Staque..." << endl;
    printStaque(a);
    a.empty();
    if(!a.empty()){
        cout<<"\n   If You Want To Make The Staque Empty, Press ";  // user can remove all items
        userChoice();
        cout<< "\n   Popping The Staque...\n"<<endl;
        while(!a.empty()){
            a.pop();
        }
        printStaque(a);
        emptyChecker(a);
    }
}

    cout<<"\n\n\t\t\t << THAT'S ALL! >>\n";
    cout<<"\n\t IF YOU WANT TO CREATE NEW STAQUE AGAIN, PRESS << Y >> "<<endl;
    cout<<"\n\t OTHERWISE, PRESS ANY KEY TO EXIT. "<<endl;
    char option;
    while(!(cin>>option)){
        cin.clear();
        cin.ignore(100, '\n');
    }
    if(option == 'Y' || option == 'y'){
        b = true;
    }
    else{
        b = false;
    }
    }while(b != false);

    cout << "\n\t\t\t    << BYE >>" << endl;
    return 0;
}

// functions
void userChoice()
{
    cout << " << Y >> "<< endl;
    bool mybool=true;
    char choice;
    while(mybool)
    {
        cin>>choice;
        cin.clear();
        cin.ignore(100, '\n');
    if(choice == 'Y' || choice == 'y'){
        mybool = false;
    }
    else{
        cout<< "\n\n>> If You Want To Perform Other Modifications, Press << Y >> "<<endl;
        }
    }
}

void emptyChecker(Staque & stq)
{
    if(stq.empty())
    {
        cout<<"\t\t << The Staque is Empty >> "<<endl;
    }
    else{
        cout<<"\t << The Staques Is Not Empty >>"<<endl;
    }
    cout<<"\n";
}

void printStaque(Staque & stq)
{
    cout<<"\n   This Is Your Staque:"<<endl;
    stq.display(cout);
}


