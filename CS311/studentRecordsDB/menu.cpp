#include "menu.hpp"

Menu::Menu(vector<Student*>&vf)
{
    _vf = vf;
    cout << "Size of: " << _vf.size() << endl;
}
Menu::~Menu()
{
    cout << "Destructing!" << endl;
    for(Student* ptr : _vf)
        delete ptr;
    _vf.clear();
}
void Menu::showMenu()
{
    bool quitter = false;
    while(!quitter)
    {
        cout << menText;
        getline(cin, userBuffer);

        try
        {
            userToInt = stoi(userBuffer);
        }
        catch(std::invalid_argument& e)
        {
            cout << "Please select a valid entry.";
            continue;
        }
        catch(std::out_of_range& e)
        {
            cout << "Please select a valid entry.";
        }
        
        switch(userToInt)
        {
            case 1:
                addStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                listStudent();
                break;
            case 5:
                dumpStudent();
                break;
            case 6:
                cout << "Exiting selected\n" << endl;
                quitter = true;
                break;
            default:
                cout << "Please select a valid entry." << endl;
                continue;

        }
    }      
}
void Menu::addStudent()
{
    cout << "\nAdd Student Success!\n" << endl;
    bool addStop = false;
    bool numFound;
    while(!addStop)
    {
        numFound = false;
        cout << "Please enter student name: ";
        getline(cin,userBuffer);
        if(userBuffer.empty())
        {
            cout << "\nEmpty input detected" << endl;
            continue;
        } else if(isspace(userBuffer.at(0))) 
        {
            // disallow white space as first char
            cout << "\nWhite space detected!" << endl;
            continue;
        }
        int i = 0;
        cout << "userBuffer size is: " << userBuffer.size() << endl;
        while(userBuffer[i])
        {
            // disallow non alphabetics
            if(!isalpha(userBuffer[i]))
            {
                cout << "\nNumeric value detected!" << endl;
                numFound = true;
                i = 0;
                break;
            }
            i++;
        }
        if(numFound)
        {
            cout <<"\nIn Numfound" << endl;
            continue;
        }
        cout << "\n\nName entered is: " << userBuffer << endl;
        break;
    }
}
void Menu::removeStudent()
{
    cout << "\nRemove Student Success!\n" << endl;
}
void Menu::searchStudent()
{
    cout << "\nSearch Student Success!\n" << endl;
}
void Menu::listStudent()
{
    cout << "\nList Student Success!\n" << endl;
}
void Menu::dumpStudent()
{
    cout << "\nDump Student Success!\n" << endl;
}
