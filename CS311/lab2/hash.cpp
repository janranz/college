#include"hash.hpp"



void Hashed::generateKey(int z)
{
    key = z % SIZE;
    bool successful = false;
    while(!successful)
    {
        if(dataList[key].getLocale() != "")
        {
            if((key + 1) < SIZE)
            {
                key += 1;
                continue;
            } else
            {
                key -= 1;
                continue;
            }
        }
        successful = true;
    }

}
void Hashed::setData(Snow obj)
{
    generateKey(obj.getZip());
    dataList[key].setLocale(obj.getLocale());
    dataList[key].setZip(obj.getZip());

}
void Hashed::dumpData()
{

}