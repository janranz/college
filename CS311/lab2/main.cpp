#include<fstream>
#include"splitter.hpp"
#include"snowFall.hpp"
#include"hash.hpp"
#include"menu.hpp"

using namespace std;

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        cout << "Please include one data file" << endl;
        exit(-1);
    }
    ifstream datF;
    datF.open(argv[1]);
    if(!datF.is_open())
    {
        cout << "File not found, please try again\n" << endl;
        exit(-1);
    }
// generate one object, make a copy of it in hashed Class
    datF.ignore(2096,'\n');
    datF.ignore(2096,'\n'); // skipping first two lines
    string ln;
    vector<string> parsed;
    while(getline(datF,ln))
    {
        vector<string> pr = splitter(ln,"\t");
        parsed.insert(parsed.end(),pr.begin(),pr.end());
    }
    datF.close();
    Snow obj;
    Hashed DB;
    int i = 0;
    int debugCount = 0;
    for(vector<string>::iterator t = parsed.begin(); t != (parsed.end()); t++)
    {
        switch(i)
        {
            case 0:// location
                obj.setLocale(*t);
                i++;
                continue;
            case 1:// zipCode
                obj.setZip(stoi(*t));
                i++;
                continue;
            case 2:// yearOne
                obj.setYears(i,stof(*t));
                i++;
                continue;
            case 3:// yearTwo
                obj.setYears(i,stof(*t));
                i++;
                continue;
            case 4:// yearThree
                obj.setYears(i,stof(*t));
                i = 0;
                goto PUSHDATA;
            default:
                continue;//nothing
        }
        PUSHDATA: DB.setData(obj);
    }
    Menu snowMen;
    snowMen.Start(DB);
    return 0;
}