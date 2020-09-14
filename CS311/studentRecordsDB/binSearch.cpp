#include "binsearch.hpp"
#include <iostream>

using std::cout;
using std::endl;
int binSearch(vector<Student*>s, int beg, int len, int targ)
{
    if(len >= beg)
    {
        int m = beg + (len - beg) / 2;

        int cand = s.at(m)->getID();
        if(cand == targ)
        {
            cout << "\nExisting ID found!" << endl;
            cout <<"Student name: " <<s.at(m)->getName()<< endl;
            cout <<"Student ID  : " <<s.at(m)->getID()<< endl;
            cout <<"Student Age : " <<s.at(m)->getAge()<< endl;
            cout <<"Student Year: " <<s.at(m)->getYear()<< endl;
            cout << setprecision(2) << fixed 
                <<"Student GPA : " <<s.at(m)->getGpa()<< endl;
            return -1;
        }
        if(cand > targ)
        {
            return binSearch(s, beg, m - 1, targ);
        }
        return binSearch(s, m + 1, len, targ);
    }
    return 0;
}

int binRemove(vector<Student*>&s, int beg, int len, int targ)
{
    if(len >= beg)
    {
        int m = beg + (len - beg) / 2;

        int cand = s.at(m)->getID();
        if(cand == targ)
        {
            cout << "\nAttempting to remove: " <<s.at(m)->getName()<< endl;
            cout << "\ncurrent size before: " << s.size() << endl;
            Student* d = s.at(m);
            delete d;
            d = NULL;
            s.erase(s.begin()+m);
            cout << "\ncurrent size after: " << s.size() << endl;

            return -1;
        }
        if(cand > targ)
        {
            return binRemove(s, beg, m - 1, targ);
        }
        return binRemove(s, m + 1, len, targ);
    }
    // std::cout << "ID not found in: " <<
    cout << "No dupes deleted" << endl;
    return 0;
}

bool sortByID(Student* left, Student* right)
{
    return left->getID() < right->getID();
}