#include "binsearch.hpp"
#include <iostream>

int binsearch(vector<Customer>c, int beg, int len, int targ)
{
    static int count = 0;
    count++;
    if(len >= beg)
    {
        int m = beg + (len - beg) / 2;

        int cand = c.at(m).getId();
        if(cand == targ)
        {
            std::cout <<"ID Found in: " << count << " iterations!" << std::endl;
            count = 0;
            return m;
        }
        if(cand > targ)
        {
            return binsearch(c, beg, m - 1, targ);
        }
        return binsearch(c, m + 1, len, targ);
    }
    std::cout << "ID not found in: " << count
              << " iterations. Returning." << std::endl;
    count = 0;
    return -1;
}