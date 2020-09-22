#pragma once
#include "snowFall.hpp"
#include<string>
#include<vector>
#include<map>
#include<iostream>

using namespace std;


#define SIZE 17389
#define MAXZIP 99999
#define MINZIP 10000

class Hashed
{
    private:
        Snow dataList[SIZE];
        Snow value;
        int key;
        int offset;
        map<int,int> keyOffsets;

    public:
        void generateKey(int);
        void setData(Snow);
        int dumpData(int);
};