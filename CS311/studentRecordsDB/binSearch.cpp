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
            cout << "\nDuplicate ID found: " <<s.at(m)->getName()<< endl;
            return -1;
        }
        if(cand > targ)
        {
            return binSearch(s, beg, m - 1, targ);
        }
        return binSearch(s, m + 1, len, targ);
    }
    // std::cout << "ID not found in: " <<
    return 0;
}
bool sortByID(Student* left, Student* right)
{
    return left->getID() < right->getID();
}