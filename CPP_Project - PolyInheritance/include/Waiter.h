#include "Employee.h"
using namespace std;
#ifndef WAITER_H
#define WAITER_H


class Waiter : public Employee
{
    public:
        Waiter(string name = "", long id = 0, double salary = 3000, string type = "WAITER", int servYears = 0);
        virtual void display(ostream & out) const;
        virtual double salaryCounter(double monthlyTip) const;

    protected:
    // data member of Waiter class
    int yearsOfService;  // for years served

};
#endif // WAITER_H
