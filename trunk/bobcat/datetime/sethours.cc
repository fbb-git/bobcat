#include "datetime.ih"

bool DateTime::setHours(int hours)
{
    if (!d_ok)
        return false;

    struct tm tmStruct = d_tm;
    tmStruct.tm_hour = hours;

    return updateTime(&tmStruct);
}
