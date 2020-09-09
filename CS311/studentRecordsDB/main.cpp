#include "student.hpp"
#include "menu.hpp"

using namespace std;
int main()
{
    vector<Student*> vf;
    Menu* interact = new Menu(vf);

    interact->showMenu();

    return 0;
}