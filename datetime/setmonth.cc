#include "datetime.ih"

#include <iostream>
using namespace std;

bool DateTime::setMonth(Month month, Relative where)
{
    if (!d_ok)
        return false;

    struct tm tmStruct = d_tm;

    switch (where)
    {
        case NEXT:
                        // For NEXT: At Sep, specify May: next year
            if (static_cast<int>(month) < d_tm.tm_mon)
                ++tmStruct.tm_year;
        break;
        case LAST:
                        // For LAST: At Sep, specify Oct: previous year
            if (static_cast<int>(month) > d_tm.tm_mon)
                --tmStruct.tm_year;
        break;
        case THIS_YEAR:
        break;
        default:
        throw Errno(1, "DateTime::setMonth(): invalid Relative spec.");
    }

    tmStruct.tm_mon = month;

    return updateTime(&tmStruct);
}




