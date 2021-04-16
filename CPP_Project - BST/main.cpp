#include <iostream>
#include "BST.h"
#include "TreeNode.h"
using namespace std;

int main()
{
    cout <<"\n\t\t              <<   WELCOME!   >> \n";
    cout <<"\n\t____________________________________________________________\n\n";
    cout <<"\t  >> Here You Can Create and Modify Binary Search Trees <<"<<endl;
    cout <<"\t "<<endl;
    cout <<"\t____________________________________________________________\n\n\n"<<endl;

    BST myBST;
    bool a = true;

    do{
    // inserting items in the tree
    cout << "   Please, Enter Items You Want To Insert In The Tree...";
    cout << "\n   Press <-100> to stop.";
    cout << "\n\n   _____________________\n\n";
    int number;
    for(;;)
    {
        cout << "     Insert Item: ";
        while(!(cin>>number)){
            cin.clear();
            cin.ignore(100, '\n');
            cout<< "\n     Please, Enter Number.  \n";
        }
        if(number == -100) break;
        myBST.insertNode(number);
    }
    cout << "\n   _____________________"<<endl;

    // performing traversals
    cout<< "\n\n >> Press <I> To See The Tree In Order."<<endl;
    cout<< " >> Press <E> To See The Tree Pre-Order."<<endl;
    cout<< " >> Press <O> To See The Tree Post_Order."<<endl;
    cout<< " >> Press <N> To Continue. \n"<<endl;
    char ch;
    while(!(ch == 'n') || !(ch != 'N'))
    {
        cin>>ch;
        myBST.display(ch);
    }
    // printing the content of BST in order after traversals
    myBST.inorderTraversal();

    // searching for an item
    cout<< "\n >> Press <F> To Search for An Item In The Tree."<<endl;
    cout<< " >> Press Any Key To Continue. \n"<<endl;
    char ch1;
    for(;;)
    {
        cin>>ch1;
        if((ch1 == 'F' || ch1 == 'f'))
            {
                cout<< "\n\n    Search For Item:  ";
                int num;
                while(!(cin>>num)){
                cin.clear();
                cin.ignore(100, '\n');
                cout<< "\n     Please, Enter Number.  \n";
                }
                cout<< (myBST.searchNode(num) ? "\n \t\t\t\t   << Found >>" : "\n \t\t\t\t << Not Found >>" )<<endl;
            }
        else
            break;
    }

    //  removing items
    cout<< "\n\n >> You Can Remove An Item From The Tree."<<endl;
    cout<< " >> Press < Y > To Modified Tree. "<<endl;
    cout<< " >> Press Any Key To Continue. \n"<<endl;
    char ch5;
    cin>>ch5;
    if(ch5 == 'Y' || ch5 == 'y')
    {
        cout<< "\n >> Press < -100 > To Stop And See Modified Tree. \n"<<endl;
        int rem;
        for (;;)
       {
            cout<< "\n\n    Removing an item: ";
            while(!(cin>>rem)){
                cin.clear();
                cin.ignore(100, '\n');
                cout<< "\n     Please, Enter Number.  \n";
            }
            if (rem == -100) break;
            myBST.removeNode(rem);
       }
    cout<< "\n\n After Removing Items: \n";
    }
    else
        cout<<"\n";

    // printing BST after modifications
    myBST.inorderTraversal();

    cout<<"\n\n\n If You Want To Continue Modification, Press  << Y >> "<<endl;
    cout<<"\n Or, Press any key to exit... ";
    char option;
    cin>>option;
    if(option == 'Y' || option== 'y'){
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
