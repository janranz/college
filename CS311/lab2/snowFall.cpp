#include "snowFall.hpp"

Snow::Snow()
{
    locale = "";
    zipCode = 0;
    years[0] = 0.0;
    years[1] = 0.0;
    years[2] = 0.0;
}

void Snow::setLocale(string n)
{
    locale = n;
}

void Snow::setZip(int zip)
{
    zipCode = zip;
}

void Snow::setYears(int i, float yr)
{
    int dex = i - 2;
    years[dex] = yr;
}

string Snow::getLocale()
{
    return locale;
}

int Snow::getZip()
{
    return zipCode;
}

float Snow::getYears(int i)
{
    return years[i];
}