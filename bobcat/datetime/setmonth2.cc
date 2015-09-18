#include "datetime.hh"

#include <iostream>
using namespace std;

bool DateTime::setMonth(int month)
{
    TimeStruct ts = d_tm;
    ts.tm_mon = month;

    return updateTime(ts);
}




