#include "datetime.hh"

bool DateTime::setYear(size_t year)
{
    TimeStruct ts = d_tm;
    ts.tm_year = year - 1900;

    return updateTime(ts);
}
