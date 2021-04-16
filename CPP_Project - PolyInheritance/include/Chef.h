#include "Employee.h"
using namespace std;
#ifndef CHEF_H
#define CHEF_H

class Chef : public Employee
{
    public:
        // constructor
        Chef(string name = "", long id = 0, double salary = 0, string type = "CHEF",
             double profitShare = 0.2, string cuisine = "");

        virtual void display(ostream & out) const;
        virtual double salaryCounter(double monthlyProfit) const;

    protected:
        // data members of chef class
        string chefCuisine;     // Cuisine type
        double ch_profit;       // profit for chefs
};

#endif // CHEF_H
