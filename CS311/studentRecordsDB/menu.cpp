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

        if(userBuffer.size() == 0)
        {
            cout << "Please select a valid entry.";
            continue;
        }
        if(userBuffer == "1")
        {
            cout << "One selected!";
        }
    }
    
}