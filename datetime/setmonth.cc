#include "datetime.ih"

#include <iostream>
using namespace std;

bool DateTime::setMonth(Month month, Relative where)
{
    if (!d_ok)
        return false;

    struct tm tmStruct = d_tm;

        // For LAST: At Sep, specify Oct: previous year
        // For NEXT: At Sep, specify May: next year
    if (where == LAST && static_cast<int>(month) > d_tm.tm_mon)
        --tmStruct.tm_year;
    else if (where == NEXT && static_cast<int>(month) < d_tm.tm_mon)
        ++tmStruct.tm_year;

    tmStruct.tm_mon = month;

    return updateTime(&tmStruct);
}




