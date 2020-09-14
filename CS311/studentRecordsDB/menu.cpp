#include "menu.hpp"
#include "binSearch.hpp"



Menu::Menu(vector<Student*>&vf)
{
    _vf = vf;
}
Menu::~Menu()
{
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
            continue;
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
    bool addStop = false;
    bool badFound;
    // ADD name / instantiate
    while(!addStop)
    {
        badFound = false;
        cout << "\nPlease enter student name: ";
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
        while(userBuffer[i])
        {
            // disallow non alphabetics
            if(isdigit(userBuffer[i]))
            {
                cout << "\nNumeric value detected!" << endl;
                badFound = true;
                i = 0;
                break;
            }
            i++;
        }
        if(badFound)
        {
            continue;
        }
        // instantiate Student obj
        _vf.push_back(new Student(userBuffer));
        DEX = _vf.size() - 1;
        addStop = true;
    }
    addStop = false;
    //Set ID
    while(!addStop)
    {
        badFound = false;
        cout << "Please enter student ID: ";
        getline(cin,userBuffer);
        if(userBuffer.empty())
        {
            cout << "\nEmpty input detected" << endl;
            continue;
        }
        int i = 0;
        while(userBuffer[i])
        {
            if(!isdigit(userBuffer[i]))
            {
                cout << "\nNon-Numeric value detected!" << endl;
                badFound = true;
                i = 0;
                break;
            }
            i++;
        }
        if(badFound) {continue;}

        i = 0;
        badFound = false;
        
        if(_vf.size() == 1)
        {
            _vf[DEX]->setID(stoi(userBuffer));
            addStop = true;
            continue;
        }
        sort(_vf.begin(),_vf.end(),sortByID);
        if(binSearch(_vf,0,DEX,stoi(userBuffer)))
        { //Duplicate found
            continue;
        } else
        {
            _vf[DEX]->setID(stoi(userBuffer));
            addStop = true;
            continue;
        }
    }
    addStop = false;
    //Set Age
    while(!addStop)
    {
        badFound = false;
        cout << "Please enter student Age: ";
        getline(cin,userBuffer);
        if(userBuffer.empty())
        {
            cout << "\nEmpty input detected" << endl;
            continue;
        }
        int i = 0;
        while(userBuffer[i])
        {
            if(!isdigit(userBuffer[i]))
            {
                cout << "\nNon-Numeric value detected!" << endl;
                badFound = true;
                i = 0;
                break;
            }
            i++;
        }
        if(badFound) {continue;}
        i = 0;
        badFound = false;
        _vf[DEX]->setAge(stoi(userBuffer));
        addStop = true;
    }
    addStop = false;

    //Set Year
    while(!addStop)
    {
        badFound = false;
        cout << "Please enter student Year(1-4): ";
        getline(cin,userBuffer);
        if(userBuffer.empty())
        {
            cout << "\nEmpty input detected" << endl;
            continue;
        }
        int i = 0;
        while(userBuffer[i])
        {
            if(!isdigit(userBuffer[i]))
            {
                cout << "\nNon-Numeric value detected!" << endl;
                badFound = true;
                i = 0;
                break;
            }
            i++;
        }
        if(badFound) {continue;}
        i = 0;
        badFound = false;
        _vf[DEX]->setYear(stoi(userBuffer));
        addStop = true;
    } 
    addStop = false;
    //Set Gpa
    while(!addStop)
    {
        badFound = false;
        cout << "Please enter student GPA: ";
        getline(cin,userBuffer);
        if(userBuffer.empty())
        {
            cout << "\nEmpty input detected" << endl;
            continue;
        }
        if(userBuffer.find_first_not_of("1234567890.-") != string::npos)
        {
            cout << "\nInvalid entry!" << endl;
            continue;
        } else
        {
            _vf[DEX]->setGpa(stof(userBuffer));
            addStop = true;
        }
    }
    addStop = false;
}

void Menu::removeStudent()
{
    bool remStop = false;
    bool badFound;
    while(!remStop)
    {
        badFound = false;
        cout << "\nPlease enter student ID ('q' to quit): ";
        getline(cin,userBuffer);
        if(userBuffer.empty())
        {
            cout << "\nEmpty input detected" << endl;
            continue;
        } else if(isspace(userBuffer.at(0))) // redundant
        {
            cout << "\nWhite space detected!" << endl;
            continue;
        }
        if(userBuffer[0] == 'q')
        {
            cout << "\nReturning to main menu!" << endl;
            remStop = true;
            continue;
        }
        int i = 0;
        while(userBuffer[i])
        {
            if(!isdigit(userBuffer[i]))
            {
                cout << "\nInvalid input. Please try again" << endl;
                badFound = true;
                break;   
            }
            i++;
        }
        if(badFound){continue;}
        int success = binRemove(_vf,0,DEX,stoi(userBuffer));
        if(success)
        {
            sort(_vf.begin(),_vf.end(),sortByID);
            DEX = _vf.size() - 1;
            remStop = true;
        }  
    }
}
void Menu::searchStudent()
{
    bool searchStop = false;
    bool badFound;
    while(!searchStop)
    {
        badFound = false;
        cout << "\nPlease enter a student ID to remove ('q' to quit): ";
        getline(cin,userBuffer);
        if(userBuffer.empty() || isspace(userBuffer.at(0)))
        {
            cout << "\nInvalid entry" << endl;
            continue;
        }
        if(userBuffer[0] =='q')
        {
            cout << "\nReturning to main menu!" << endl;
            searchStop = true;
            continue;
        }
        int i = 0;
        while(userBuffer[i])
        {
            if(!isdigit(userBuffer[i]))
            {
                cout << "\nInvalid entry" << endl;
                badFound = true;
                break;
            }
            i++;
        }
        if(badFound){continue;}
        int searching = binSearch(_vf,0,DEX,stoi(userBuffer));
        if(!searching)
        {
            cout <<"\nID does not exist!" << endl;
        }
        searchStop = true;
    }
}
void Menu::listStudent()
{
    if(DEX < 0)
    {
        cout <<"\nPlease add students to database before using this function\n";
        return;
    }
    sort(_vf.begin(),_vf.end(),sortByID);
    for(int i = 0; i < DEX + 1; i++)
    {
        cout <<"Student name: " <<_vf[i]->getName()<< endl;
        cout <<"Student ID  : " <<_vf[i]->getID()<< endl;
        cout <<"Student Age : " <<_vf[i]->getAge()<< endl;
        cout <<"Student Year: " <<_vf[i]->getYear()<< endl;
        cout << fixed << setprecision(2);
        cout <<"Student GPA : " <<_vf[i]->getGpa()<< endl;
        cout << endl;
    }
}
void Menu::dumpStudent()
{
    bool dumpStop = false;
    if(DEX <0)
    {
        cout <<"\nPlease add students to database before using this function\n";
        return;
    }

    string fileName;
    cout << "\nPlease enter a file name to write out to: " << endl;

    getline(cin,userBuffer);
    if(userBuffer.empty())
    {
        fileName = "studentDB.txt";
    }
    fileName = userBuffer;
    fileName.append(".txt");
    dump.open(fileName);
    sort(_vf.begin(),_vf.end(),sortByID);
    for(int i = 0; i < DEX + 1; i++)
    {
        dump <<"Student name: " <<_vf[i]->getName()<< endl;
        dump <<"Student ID  : " <<_vf[i]->getID()<< endl;
        dump <<"Student Age : " <<_vf[i]->getAge()<< endl;
        dump <<"Student Year: " <<_vf[i]->getYear()<< endl;
        dump << fixed << setprecision(2);
        dump <<"Student GPA : " <<_vf[i]->getGpa()<< endl;
        dump << endl;
    }
    dump.close();
}
