#pragma once
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class IpNodes
{
    private:
        string ipAddress; //key
        int occurs = 1; //init to 1 due to firstGo exception
        IpNodes* next = nullptr;

    public:
        void setIP(string);
        void setNext(IpNodes*);
        string getIP();
        IpNodes* getNext();
        int getCount();
        void updateCount();
};
void addNode(IpNodes**,string);
void searchNode(int,IpNodes**,string option = "");
void mainMenu(IpNodes**);