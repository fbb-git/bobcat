#include "datetime.ih"

bool DateTime::setTime(time_t seconds)
{
    TimeStruct tmStruct;
    utcSec2timeStruct(&tmStruct, seconds);
    if (d_ok)
    {
        d_time = seconds;
        d_tm = tmStruct;
    }
    return d_ok;
}
