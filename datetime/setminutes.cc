#include "datetime.hh"

bool DateTime::setMinutes(int minutes)
{
    TimeStruct  ts = d_tm;
    ts.tm_min = minutes;

    return updateTime(ts);
}
