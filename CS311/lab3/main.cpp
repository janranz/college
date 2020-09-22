#include<iostream>
#include<fstream>
#include"splitter.hpp"
#include"IpNodes.hpp"

using namespace std;

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        cout << "Please include a data file" << endl;
        exit(-1);
    }
    ifstream datF;
    datF.open(argv[1]);
    if(!datF.is_open())
    {
        cout << "File not found, please try again" << endl;
        exit(-1);
    }
    //reading in text file (no lines to skip / no type changes)
    string ln;
    vector<string> parsed;
    while(getline(datF,ln))
    {
        vector<string> pr = splitter(ln,"\n");
        parsed.insert(parsed.end(),pr.begin(),pr.end());
    }
    datF.close();

    IpNodes* head = nullptr;


    for(vector<string>::iterator t = parsed.begin(); t != (parsed.end()); t++)
    {
        addNode(&head, *t);
        searchNode(head, *t, 1); //Modes: (1) - Tally mode | (2) - Query mode
    }
    searchNode(head,"",2);


    return 0;
}
