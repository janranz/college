#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include"hash.hpp"

using namespace std;

class Menu
{
    private:
    string userBuffer;
    string mainMenu;
    int userToInt;

    public:
    Menu();
    void Start(Hashed&);
};