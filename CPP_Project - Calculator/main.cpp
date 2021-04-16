#include <iostream>
#include <stdlib.h>
#include <new>
using namespace std;

void Addition(double *x, double *y);
void Subtraction(double *x, double *y);
void Multiplication(double *x, double *y);
void Division(double *x, double *y);

int main()
{
    double *x = new(nothrow) double;
    double *y = new(nothrow) double;
    char *choice = new(nothrow) char;
    int *a = new(nothrow) int;

    if (!x){
            cout << "Memory Allocation Failed";
        }
    if (!y){
            cout << "Memory Allocation Failed";
        }

    if (!choice){
            cout << "Memory Allocation Failed";
        }

    if (!a){
            cout << "Memory Allocation Failed";
        }

    *a = 1;

    do{
    system("COLOR 03");
    cout<< "\n\t     WELCOME TO MY CALCULATOR!\n\n";
    cout<< "\tYOU CAN USE THE FOLLOWING OPPERATIONS: \n\n";
    cout<< "\t\t  (+)  (-)  (*)  (/) \n";
    cout<< "";
    cout<< "\t _________________________________\n";
    cout<< "\t _________________________________\n";
    cout<< "\t|       |       |       |         |\n";
    cout<< "\t|   1   |   2   |   3   |    +    |\n";
    cout<< "\t|_______|_______|_______|_________|\n";
    cout<< "\t _________________________________\n";
    cout<< "\t|       |       |       |         |\n";
    cout<< "\t|   4   |   5   |   6   |    -    |\n";
    cout<< "\t|_______|_______|_______|_________|\n";
    cout<< "\t _________________________________\n";
    cout<< "\t|       |       |       |         |\n";
    cout<< "\t|   7   |   8   |   9   |    *    |\n";
    cout<< "\t|_______|_______|_______|_________|\n";
    cout<< "\t _________________________________\n";
    cout<< "\t|                       |         |\n";
    cout<< "\t|           0           |    /    |\n";
    cout<< "\t|_______________________|_________|\n";
    cout<< "\t _________________________________\n\n";


    B:
    cout<< "\t  Enter First Operand: \t";
    while(!(cin>>*x)) //checks whether the input is number or not
    {
        cout<< "\n\t _________________________________\n\n";
        cout<< "\t  Invalid Input.\n";
        cin.clear();
        cin.ignore(50, '\n');
        cout<< "\t  Please, Enter a number.\n";
        cout<< "\t _________________________________\n\n";
        goto B;
    }

    C:
    cout<< "\t  Enter Second Operand:\t";
    while(!(cin>>*y))
    {
        cout<< "\n\t _________________________________\n\n";
        cout<< "\t  Invalid Input.\n";
        cin.clear();
        cin.ignore(50, '\n');
        cout<< "\t  Please, Enter a number.\n";
        cout<< "\t _________________________________\n\n";
        goto C;
    }

    D:
    cout<< "\t  Enter an Operation:  \t";
    cin>>*choice;
    cout<< "\n\n";

    switch(*choice){
            case'+':
                Addition(x, y);
                break;
            case'-':
                Subtraction(x,y);
                break;
            case'*':
                Multiplication(x,y);
                break;
            case'/':
                Division(x,y);
                break;
            default:  // checks whether the input is one of the four operations or not
                cout<< "\n\t _________________________________\n\n";
                cout<< "\t  Invalid Input.\n";
                cin.clear();
                cin.ignore(50, '\n');
                cout<< "\t  Enter one of the operations: \n\n";
                cout<< "\t\t (+)  (-)  (*)  (/) \n";
                cout<< "\t _________________________________\n\n";
                goto D;
        }
        cout<< "\n\t _________________________________\n\n";

    F:
    cout<< "\t     DO YOU WANT TO CONTINUE? ";
    cout<< "\n\t _________________________________\n";
    cout<< "\t|                |                |\n";
    cout<< "\t|       YES      |       NO       |\n";
    cout<< "\t|     << 1 >>    |     << 0 >>    |\n";
    cout<< "\t|________________|________________|\n\n";

    cin>>*choice;  // checks whether the input is 1 or 0 or not
    if(*choice=='1')  // if input is one, user can go on calculations
        {
            system("CLS");
        }
    else if(*choice=='0')  // if input is one, user exits
        {
            cout << "\n\t\t      >> BYE <<\n\n\n\n";
            *a=0;
        }
    else
        {
            goto F; // if input is something other than 0 or 1, asks again if continue
        }


    }while(*a!=0);

    delete x;
    delete y;
    delete choice;
    delete a;

}

void Addition(double *x, double *y){
    cout <<"\t\t"<< *x << " + " << *y << " = "<< *x+(*y) <<endl;
}
void Subtraction(double *x, double *y){
    cout <<"\t\t"<< *x << " - " << *y << " = "<< *x-*y <<endl;
}
void Multiplication(double *x, double *y){
    cout <<"\t\t"<< *x << " * " << *y << " = "<< (*x)*(*y) <<endl;
}
void Division(double *x, double *y){
    if(*y==0){
    cout <<"\t          >> UDEFINED << \n";  // in the case of division by 0
    }
    else
        cout <<"\t\t"<< *x << " / " << *y << " = "<< *x/(*y) <<endl;
}
