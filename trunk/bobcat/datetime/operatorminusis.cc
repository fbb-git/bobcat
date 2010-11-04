#include "datetime.ih"

DateTime &DateTime::operator-=(TimeStruct const &fields)
{
    TimeStruct ts = d_tm;

    ts.tm_sec -= fields.tm_sec;
    ts.tm_min -= fields.tm_min;
    ts.tm_hour -= fields.tm_hour;
    ts.tm_mday -= fields.tm_mday;
    ts.tm_mon -= fields.tm_mon;
    ts.tm_year -= fields.tm_year;

    updateTime(ts);

    return *this;
}
