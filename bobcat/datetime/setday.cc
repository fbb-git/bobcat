#include "datetime.ih"

bool DateTime::setDay(int day)
{
    if (!d_ok)
        return false;

    struct tm tmStruct = d_tm;
    tmStruct.tm_mday = day;

    return updateTime(&tmStruct);
}
