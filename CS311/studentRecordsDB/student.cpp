#include "student.hpp"

Student::Student(string n)
{
    name = n;
}
void Student::setID(int n)
{
    idNumber = n;
}
void Student::setAge(int n)
{
    age = n;
}
void Student::setYear(int n)
{
    year = n;
}
void Student::setGpa(float n)
{
    gpa = n;
}
string Student::getName()
{
    return name;
}
int Student::getID()
{
    return idNumber;
}
int Student::getAge()
{
    return age;
}
int Student::getYear()
{
    return year;
}
float Student::getGpa()
{
    return gpa;
}