#include "datetime.hh"

bool DateTime::setFields(TimeStruct const &time, int fields)
{
    TimeStruct ts = d_tm;

    if (fields & SECONDS)
        ts.tm_sec = time.tm_sec;

    if (fields & MINUTES)
        ts.tm_min = time.tm_min;

    if (fields & HOURS)
        ts.tm_hour = time.tm_hour;

    if (fields & MONTHDAY)
        ts.tm_mday = time.tm_mday;

    if (fields & MONTH)
        ts.tm_mon = time.tm_mon;

    if (fields & YEAR)
        ts.tm_year = time.tm_year;


    return updateTime(ts);
}
