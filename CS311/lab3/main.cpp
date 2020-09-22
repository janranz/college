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
    bool matchFound = false;

    for(vector<string>::iterator t = parsed.begin(); t != (parsed.end()); t++)
    {
        if(!matchFound)
        {
            addNode(&head,*t);
        }
       matchFound = searchNode(1, head, *t); //Modes: (1) - Tally mode

    }
    searchNode(2, head);
    mainMenu(head);


    return 0;
}
