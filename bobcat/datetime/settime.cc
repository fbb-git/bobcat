#include "datetime.ih"

bool DateTime::setTime(time_t seconds)
{
    TimeStruct tmStruct;
    bool ok = utcSec2timeStruct(&tmStruct, seconds);
    if (ok)
    {
        d_ok = true;
        d_time = seconds;
        d_tm = tmStruct;
    }
    return ok;
}
