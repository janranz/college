#include "snowFall.hpp"

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
float* Snow::getYears()
{
    return years;
}