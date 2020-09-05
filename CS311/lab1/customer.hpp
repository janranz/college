#pragma once
#include <string>
using std::string;

class Customer
{
    private:
        string name;
        int id, age;
        float bal;
    
    public:
        Customer(string n);
        void setId(int n);
        void setAge(int n);
        void setBal(float n);
        void helpCall(int n,int c = 0, float b = 0);
        string getName();
        int getId();
        int getAge();
        float getBal();
};