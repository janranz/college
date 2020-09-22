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
#define YEARS 3

class Hashed
{
    private:
        Snow dataList[SIZE];
        Snow value;
        int key;
        int offset;
        float localAvg;
        float localMax;
        map<int,int> keyOffsets;

    public:
        void generateKey(int);
        void setData(Snow);
        void dumpData(int);
        void findTotals(int);
        void prettyOutput(int);
};