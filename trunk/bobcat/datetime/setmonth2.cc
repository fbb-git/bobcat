#include "datetime.ih"

#include <iostream>
using namespace std;

bool DateTime::setMonth(int month)
{
    if (!d_ok)
        return false;

    struct tm tmStruct = d_tm;
    tmStruct.tm_mon = month;

    return updateTime(&tmStruct);
}




