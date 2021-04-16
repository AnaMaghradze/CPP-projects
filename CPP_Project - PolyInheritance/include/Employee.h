using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
    public:
        // Employee constructor
        Employee(string name = "", long id = 0, double salary = 0, string type = "");
        // member functions
        virtual void display(ostream & out) const;    // polymorphic display() function
        virtual double salaryCounter(double monthlyProfit) const;   // polymorphic salaryCounter() function

    protected:
        // data members
        string empName;     // employee name
        long empID;         // employee id number
        int empSalary;      // employee salary
        string empType;     // employee type - owner, chief, or waiter

};

#endif // EMPLOYEE_H
