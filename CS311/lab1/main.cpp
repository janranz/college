#include <iostream>
#include <fstream>
#include <sstream>
#include "splitter.hpp"
#include "customer.hpp"
#include "binsearch.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        cout << "Please specify the list (text file)." << endl;
        exit(-1);
    }
    ifstream cd;
    cd.open(argv[1]);
    cd.ignore(2096,'\n');
    cd.ignore(2096,'\n'); //skipping first two lines
    cout.precision(2);
    cout << fixed;
    string ln;
    vector<string> parsed;
    while(getline(cd,ln))
    {
        vector<string> pr = splitter(ln, "\t");
        parsed.insert(parsed.end(), pr.begin(), pr.end());
    }
    cd.close();

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
            cuspool.push_back(Customer(*t));
        }
        else if( i == 1 || i == 2)
        {
            cuspool.at(dex).helpCall(i,stoi(*t));
        }
        else if( i == 3)
        {
            cuspool.at(dex).helpCall(i, 0, stof(*t));
        }
        i++;
    }
    dex = cuspool.size() - 1 ;

    string userIDstr;
    int userIDint;

    STARTQ:
    do
    {
        cout << "\nPlease enter an ID (type q to quit): ";
        getline(cin,userIDstr);
        if(userIDstr == "q" || userIDstr == "Q")
        {
            cout << "\nquit received! Exiting..." << endl;
            exit(0);
        }
        stringstream s(userIDstr);
        if(s >> userIDint)
        {
            if(s.eof())
            {
                break;
            }
        }
        cout << "\nNon-Int submitted, please try again!" << endl;
    } while (1);
    

    cout << "\nAccepted... Searching for ID:\t" << userIDint << endl;

    int result = binsearch(cuspool,0,dex,userIDint);

    if(result == -1)
    {
        cout << "\nID Does not exist" << endl;
        goto STARTQ;
    }
    else
    {
        cout << "\nID Exists at index: " << result << endl;
        cout << "\nPerson:\t" << cuspool.at(result).getName() << endl;
        cout << "ID:\t" << cuspool.at(result).getId() << endl;
        cout << "Age:\t" << cuspool.at(result).getAge() << endl;
        cout << "Bal:\t" << cuspool.at(result).getBal() << endl;
        goto STARTQ;
    }
    return 0;
}