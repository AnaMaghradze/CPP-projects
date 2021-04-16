#include <iostream>
#include <string>
using namespace std;
#include "Employee.h"

// definition of Employee's constructor
Employee::Employee(string name, long id, double salary, string type)
    : empName(name), empID(id), empSalary(salary), empType(type) {}

// definition of display() function
void Employee::display(ostream & out) const
{
    out << "\n\t______________________________\n"
        << "\n\t > Employee Type:     " << empType
        << "\n\t > Employee Name:     " << empName
        << "\n\t > Employee ID:       " << empID
        << "\n\t > Monthly Salary:    $" << empSalary;
}

void Employee::display(ostream & out)const;
double Employee::salaryCounter(double monthlyProfit) const
{
    return monthlyProfit;
}

// operator overloading
ostream & operator<<(ostream & out, const Employee & emp)
{
    emp.display(out);
    return out;
}



