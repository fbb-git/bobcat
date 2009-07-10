#include "datetime.ih"

#include <iostream>
using namespace std;

bool DateTime::setMonth(Month month, Relative where)
{
    TimeStruct ts = d_tm;

    switch (where)
    {
        case NEXT:
                        // For NEXT: At Sep, specify May: next year
            if (static_cast<int>(month) < d_tm.tm_mon)
                ++ts.tm_year;
        break;

        case LAST:
                        // For LAST: At Sep, specify Oct: previous year
            if (static_cast<int>(month) > d_tm.tm_mon)
                --ts.tm_year;
        break;

        case THIS_YEAR:
        break;

        default:
        throw Errno(1, "DateTime::setMonth(): invalid Relative spec.");
    }

    ts.tm_mon = month;

    return updateTime(ts);
}




