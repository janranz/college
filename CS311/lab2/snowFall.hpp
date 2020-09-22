#pragma once
#include<string>
#include <iomanip>
using std::string;


class Snow
{
    private:
        string locale;
        int zipCode; // key
        float years[3];

    public:
        Snow();
        void setLocale(string);
        void setZip(int);
        void setYears(int,float);

        string getLocale();
        int getZip();
        float getYears(int);
};