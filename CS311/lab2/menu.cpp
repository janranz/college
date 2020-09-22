#include"menu.hpp"

Menu::Menu()
{
    mainMenu = "\nPlease enter a zip-code or enter (q) to quit: ";
}

void Menu::Start(Hashed& DB)
{
    bool quitter = false;
    while(!quitter)
    {
        quitter = false;
        cout << mainMenu;
        getline(cin,userBuffer);
        if(userBuffer == "q" || userBuffer == "Q")
        {
            quitter = true;
            continue;
        }
        try
        {
            userToInt = abs(stoi(userBuffer));
        }
        catch(std::invalid_argument& e)
        {
            cout << "\nInvalid entry, please try again.";
            continue;
        }
        catch(std::out_of_range& e)
        {
            cout << "\nInvalid entry, please try again.";
            continue;
        }
        if(userToInt > MAXZIP || userToInt < MINZIP)
        {
            cout << "\nInput out of bounds! Please try again.";
            continue;
        }
        DB.dumpData(userToInt);
    }
}