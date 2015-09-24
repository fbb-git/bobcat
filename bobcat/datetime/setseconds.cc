#include "datetime.ih"

bool DateTime::setSeconds(int seconds)
{
    TimeStruct ts = d_tm;
    ts.tm_sec = seconds;

    return updateTime(ts);
}
