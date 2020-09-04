#include <iostream>
#include <fstream>
#include "splitter.hpp"
#include "customer.hpp"
using namespace std;

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        cout << "Please specify a single list (text file)." << endl;
        exit(-1);
    }
    ifstream cd;
    cd.open(argv[1]);
    cd.ignore(2096,'\n');
    cd.ignore(2096,'\n');

    string ln;
    vector<string> parsed;
    while(getline(cd,ln))
    {
        vector<string> pr = splitter(ln, "\t");
        parsed.insert(parsed.end(), pr.begin(), pr.end());
    }
    int i = 0;
    int dex = 0;
    vector<Customer> cuspool;
    for(vector<string>::iterator t = parsed.begin(); t != (parsed.end()); t++)
    {      
        if(i%4 == 0 && i)
        {
            dex++;
            i = 0;
        }
        if(i == 0)
        {
            cout << "New customer:\t" << *t << endl;
            cuspool.push_back(Customer(*t));
        }
        else if( i == 1 || i == 2)
        {
            cuspool.at(dex).helpCall(i,stoi(*t));
        }
        else if( i == 3)
        {
            cuspool.at(dex).helpCall(i,stof(*t));
        }
        i++;   
    }
    return 0;
}