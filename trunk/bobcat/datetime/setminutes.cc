#include "datetime.ih"

bool DateTime::setMinutes(int minutes)
{
    if (!d_ok)
        return false;

    struct tm tmStruct = d_tm;
    tmStruct.tm_min = minutes;

    return updateTime(&tmStruct);
}
