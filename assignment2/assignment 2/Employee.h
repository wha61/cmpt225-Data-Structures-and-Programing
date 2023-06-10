#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <iostream>
#include <string>

using namespace std;

//Employee class for testReverseEmployees() function
class Employee
{
private:
    string name;
    int id;
public:
    Employee(string n, int i);//constructor with two arguements
    //getters
    string getName() const;
    int getID() const;
    //function to combine string and int toghther as a new string
    string toString() const;
};
#endif