#include "Employee.h"
using namespace std;
#ifndef OWNER_H
#define OWNER_H


class Owner : public Employee
{
    public:
        // constructor
        Owner(string name = "", long id = 0, double salary = 15000, string type = "OWNER", double profitShare = 0.6);

        virtual void display(ostream & out) const;
        virtual double salaryCounter(double monthlyProfit) const;

    protected:
        // data members of Owner class
        double o_profit;    // profit for owner
};

#endif // OWNER_H
