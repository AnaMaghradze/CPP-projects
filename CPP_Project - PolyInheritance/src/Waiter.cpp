#include <iostream>
#include <string>
using namespace std;
#include "Waiter.h"
#include "Employee.h"

// // definition of Waiter constructor
Waiter::Waiter(string name, long id, double salary, string type, int servYears)
    : Employee(name, id, salary, type), yearsOfService(servYears)
    {}

// definition of display() function
void Waiter::display(ostream & out) const
{
    Employee::display(out);
    out << "\n\t > Years Of Service:  "<<yearsOfService
        << "\n\t > Monthly Profit:    Tips Based";
}

// definition of function  salaryCounter() for Chef class
double Waiter::salaryCounter(double monthlyTip) const
{
    double w_profit;
    w_profit = empSalary + monthlyTip;
    cout<<"\n\t > Salary (+Tips):    $"<< w_profit<<endl;

    return w_profit;
}
