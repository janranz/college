#include "customer.hpp"

Customer::Customer(string n)
{
    name = n;
}
void Customer::setId(int n)
{
    id = n;
}
void Customer::setAge(int n)
{
    age = n;
}
void Customer::setBal(float n)
{
    bal = n;
}
void Customer::helpCall(int n, int c, float b)
{
    switch(n)
    {
        case 1: setId(c);
                break;
        case 2: setAge(c);
                break;
        case 3: setBal(b);
                break;
        default: // will never default
                break;
    }
}
string Customer::getName()
{
    return name;
}
int Customer::getId()
{
    return id;
}
int Customer::getAge()
{
    return age;
}
float Customer::getBal()
{
    return bal;
}