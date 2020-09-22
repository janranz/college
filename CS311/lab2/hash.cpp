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
            offset = i - 1;
        }
    }
    if(offset > 0)
    {
        keyOffsets.insert(pair<int,int>(z,offset));
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

void Hashed::findTotals(int m)
{
    localMax = 0;
    for(int i = 0; i < YEARS; i++)
    {
        localMax += dataList[m].getYears(i);
    }
    localAvg = localMax / YEARS;
}

void Hashed::prettyOutput(int key)
{
    cout << "\n\t---RESULTS---\n" << endl;
    cout << "Location: " << dataList[key].getLocale() << endl;
    cout << "Zip Code: " << dataList[key].getZip() << endl;
    for(int i = 0; i < YEARS; i++)
    {
        cout << "Year " << i+1 << ":\t" << dataList[key].getYears(i) << endl;
    }
    cout << "Average Snow Fall: " << localAvg << endl;
    cout << "Maximum Snow Fall: " << localMax << endl;
}

void Hashed::dumpData(int userZip)
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
    cout << "\n\n\t(DEBUG) Zip at offset: " << key << endl;
    if(dataList[key].getZip() == 0)
    {
        //bad zip
        cout << "ZIP Not found!" << endl;
        return;
    }
    findTotals(key);
    prettyOutput(key);
}