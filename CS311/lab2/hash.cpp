#include"hash.hpp"



void Hashed::generateKey(int z)
{
    key = z % SIZE;
    int offset = 0;
    int i = 1;

    while(dataList[key].getZip() != 0)
    {
        key = (z + i) % SIZE;
        i++;
        if(i > 1)
        {
            offset = i;
        }
    }
    if(offset > 0)
    {
        keyOffsets.insert(pair<int,int>(z,offset));
        // keyOffsets[z] = offset;
    }
}
void Hashed::setData(Snow obj)
{
    generateKey(obj.getZip());
    dataList[key].setLocale(obj.getLocale());
    dataList[key].setZip(obj.getZip());
    for(int i = 0; i < 3; i++)
    {
        dataList[key].setYears(i+2,obj.getYears(i));
    }
}
int Hashed::dumpData(int userZip)
{
    //Check if userZip requires offset
    auto check = keyOffsets.find(userZip);
    if(check == keyOffsets.end())
    {
        cout << "No adjustments" << endl;
        offset = 0;
    }
    else
    {
        offset = check->second;
        cout << "Adjusting offset: " << offset << endl;
    }
    //Check if userZip even exists
    key = (userZip + offset) % SIZE;
    if(dataList[key].getZip() == 0)
    {
        //bad zip
        cout << "Baddie!" << endl;
        return 1;
    }
    cout <<"\nSuccessful dump for: " << userZip << endl;
    cout <<"\nLocation: " << dataList[key].getLocale() << endl;
    cout <<"\nZip: " << dataList[key].getZip() << endl;
    cout <<"\nYear 1: " << dataList[key].getYears(0) << endl;
    cout <<"\nYear 2: " << dataList[key].getYears(1) << endl;
    cout <<"\nYear 3: " << dataList[key].getYears(2) << endl;

    return 0;
}