#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"
#include "Owner.h"

// definition of Owner constructor
Owner::Owner(string name, long id, double salary, string type, double profitShare)
    : Employee(name, id, salary, type),
      o_profit(profitShare)
      {}

// definition of display() function
void Owner::display(ostream & out) const
{
    Employee::display(out);
    out << "\n\t > Profit Share:      60%";
}

// definition of function  salaryCounter() for Owner class
double Owner::salaryCounter(double monthlyProfit) const
{
    double ownerSalary;
    ownerSalary = empSalary + monthlyProfit*(o_profit);
    cout<<"\n\t > Salary (+Profit):  $"<< ownerSalary <<endl;

    return ownerSalary;
}
