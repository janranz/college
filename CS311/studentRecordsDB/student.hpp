#pragma once
#include <string>


using std::string;

class Student
{
    private:
        string name;
        int idNumber;
        int age;
        int year;
        float gpa;

    public:
        Student(string n);
        void setID(int id);
        void setAge(int n);
        void setYear(int n);
        void setGpa(float n);

        string getName();
        int getID();
        int getAge();
        int getYear();
        float getGpa();
};