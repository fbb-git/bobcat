#include "datetime.hh"

bool DateTime::setDay(int day)
{
    struct tm tmStruct = d_tm;
    tmStruct.tm_mday = day;

    return updateTime(tmStruct);
}

