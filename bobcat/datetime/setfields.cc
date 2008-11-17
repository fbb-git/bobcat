#include "datetime.ih"

bool DateTime::setFields(TimeStruct const &time, int fields)
{
    TimeStruct tmStruct = d_tm;

    if (fields & SECONDS)
        tmStruct.tm_sec = time.tm_sec;

    if (fields & MINUTES)
        tmStruct.tm_min = time.tm_min;

    if (fields & HOURS)
        tmStruct.tm_hour = time.tm_hour;

    if (fields & MONTHDAY)
        tmStruct.tm_mday = time.tm_mday;

    if (fields & MONTH)
        tmStruct.tm_mon = time.tm_mon;

    if (fields & YEAR)
        tmStruct.tm_year = time.tm_year;


    return updateTime(&tmStruct);
}
