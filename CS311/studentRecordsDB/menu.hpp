#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "student.hpp"

using std::string;
using std::vector;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
using std::sort;

class Menu
{
    private:
        bool yayNay = false; // general I/O
        int selector = 0; // switch-case
        string userBuffer;
        int userToInt = 0;
        ofstream dump;
        vector<Student*>_vf;
        int DEX = -1;
        string menText = "\n\nDatabase Main Menu:\n\n1.Add New Student\n2.Remove Student\n3.Search Student Record\n4.List All Students\n5.Save Student Records to File\n6. Exit\n\nEnter Choice: ";
    public:
    Menu(vector<Student*>&vf);
    ~Menu();
    void showMenu();
    void addStudent();
    void removeStudent();
    void searchStudent();
    void listStudent();
    void dumpStudent();
};
