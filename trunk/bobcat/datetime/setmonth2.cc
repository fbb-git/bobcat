#include "datetime.ih"

#include <iostream>
using namespace std;

bool DateTime::setMonth(int month)
{
    struct tm tmStruct = d_tm;
    tmStruct.tm_mon = month;

    return updateTime(&tmStruct);
}




