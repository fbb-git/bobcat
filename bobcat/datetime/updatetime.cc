#include "datetime.ih"

bool DateTime::updateTime(struct tm *tmPtr)
{
    d_ok = true;
    time_t time = d_time;

    d_time = timeStruct2utcSec(&tmStruct);
    if (!d_ok)
        d_time = time;

    utcSec2timeStruct(&d_tm, d_time);
    return d_ok;
}
