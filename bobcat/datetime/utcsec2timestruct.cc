#include "datetime.ih"

bool DateTime::utcSec2timeStruct(TimeStruct *ts, time_t time)
{
    time += d_displayZoneShift;     // add local time (if any)

    bool ret = gmtime_r(&time, ts);
    d_errno = errno;

    return ret;
}
