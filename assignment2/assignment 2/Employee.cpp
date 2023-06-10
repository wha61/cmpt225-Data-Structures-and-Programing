#include "Employee.h"

Employee::Employee(string n, int i) 
{
    name = n;
    id = i;
}
std::string Employee::getName() const
{
    return this->name;
}
int Employee::getID() const
{
    return this->id;
}
string Employee::toString() const//"string--int" form
{
    int id = this->getID();
    string str1 = this->getName();
    string str2 = " ";
    string str3 = to_string(id);
    str1 = str1 + str2 + str3;

    return str1;
}
