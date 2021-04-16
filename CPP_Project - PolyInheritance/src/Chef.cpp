#include <iostream>
#include <string>
using namespace std;
#include "Chef.h"
#include "Employee.h"

// definition of Chef constructor
Chef::Chef(string name, long id, double salary, string type, double profitShare, string cuisine)
    : Employee(name, id, salary, type),
      ch_profit(profitShare),
      chefCuisine(cuisine){}


// definition of display() function
void Chef::display(ostream & out) const
{
    Employee::display(out);
    out << "\n\t > Chef's Cuisine:    " <<chefCuisine
        << "\n\t > Profit Share:      20%";
}

// definition of function  salaryCounter() for Chef class
double Chef::salaryCounter(double monthlyProfit) const
{
    double chefSalary;
    chefSalary = empSalary + monthlyProfit * ch_profit;
    cout<<"\n\t > Salary (+Profit):  $"<< chefSalary<<endl;

    return chefSalary;
}


