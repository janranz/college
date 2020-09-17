#pragma once
#include "snowFall.hpp"
#include<string>

using std::string;

#define SIZE 17389

class Hashed
{
    private:
        Snow dataList[SIZE];
        int key;
        Snow value;

    public:
        void generateKey(int);
        void setData(Snow);
        void dumpData();
};