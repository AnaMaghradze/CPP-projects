#include <iostream>
#include <new>
using namespace std;
#include "Employee.h"
#include "Owner.h"
#include "Chef.h"
#include "Waiter.h"

int main()
{
    cout <<"\n\t\t    WELCOME TO THE FAMILY RESTAURANT!\n";
    cout <<"\n\t_________________________________________________________\n\n";
    cout <<"\t The Restaurant Has 6 Employees: \n"<<endl;
    cout <<"\t\t\t>>  1 OWNER"<<endl;
    cout <<"\t\t\t>>  2 CHEFS"<<endl;
    cout <<"\t\t\t>>  3 WAITERS"<<endl;
    cout <<"\n\t Here You Can See The Statistics About Each Employee... "<<endl;
    cout <<"\n\t__________________________________________________________\n"<<endl;

    bool a = true;
    double profitAmount, tipsAmount;
    const int size = 6;
    Employee * myArray[size];

    myArray[0] = new (nothrow) Owner("Anna", 100);
    myArray[1] = new (nothrow) Chef("Khatia", 200, 10000, "CHEF", 0.2, "Georgian");
    myArray[2] = new (nothrow) Chef("George", 300, 10000, "CHEF", 0.2, "Italian");
    myArray[3] = new (nothrow) Waiter("David", 400, 3000, "WAITER", 3);
    myArray[4] = new (nothrow) Waiter("Diana", 500, 3000, "WAITER", 5);
    myArray[5] = new (nothrow) Waiter("Andrey", 600, 3000, "WAITER", 7);

    for(int i=0; i<size; i++){
        if(myArray[i] == 0)
        {
            cout<< "Memory Allocation Failed For i = "<<i<<endl;
        }
    }

    do{
    cout<<"\n\t Please, Enter The Amount Of Monthly Profit:  $";
    while(!(cin>>profitAmount)){
        cin.clear();
        cin.ignore(100, '\n');
        cout<< "\n\t >> Please, Enter Number!    $";
    }
    // In case of negative amount, company encounters loss
    if(profitAmount < 0)
    {
        cout<< "\n\t The Company Encountered A Loss In this Particular Month.";
        cout<< "\n\t The Employees Will Get Their Base Salary Without Any Loss.";
        profitAmount = 0;  // loss doesn't affect employee's base salary
    }
    // to display data about owner and chefs
    for(int i=0; i<3; i++)
    {
        if(i<3)
        {
            myArray[i]->display(cout);
            myArray[i]->salaryCounter(profitAmount);
        }
    }
    // to display data about waiters
    int waiterCounter=1;
    for(int i=3; i<size; i++)
    {
        cout<<"\n\t Please, Enter The Amount Of Tip For Waiter #"<<waiterCounter<<":  $";
        waiterCounter++;
        while(!(cin>>tipsAmount)){
        cin.clear();
        cin.ignore(100, '\n');
        cout<< "\n\t >> Please, Enter Number!    $";
    }
    if(tipsAmount < 0)
    {
        tipsAmount = 0;   // if input is negative, doesn't affect on salary and tips of waiters
    }
        myArray[i]->display(cout);
        myArray[i]->salaryCounter(tipsAmount);
    }

    delete [] myArray;

    cout<<"\n\n\n If You Want To Try Different Profit And Tips, Press  << Y >> "<<endl;
    cout<<"\n Or, Press any key to exit... ";
    char opt;
    cin>>opt;
    if(opt == 'Y' || opt== 'y'){
        a = true;
    }
    else{
        a = false;
    }
    cout<<"\n __________________________________________________________________";
    cout<<"\n\n\n\n";

    }while(a != false);

    return 0;
}



