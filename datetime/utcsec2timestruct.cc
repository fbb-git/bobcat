#include "datetime.ih"

void DateTime::utcSec2timeStruct(TimeStruct *ts, time_t time)
{
    time += d_displayZoneShift;     // add local time shift (if any)

    d_ok = gmtime_r(&time, ts);

    ts->tm_isdst = d_dstShift != 0;
}

