#pragma once
#include<string>
#include<iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class IpNodes
{
    private:
        string ipAddress; //key
        int occurs = 0;
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
void searchNode(IpNodes*,string,int);