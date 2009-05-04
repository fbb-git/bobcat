#include "datetime.ih"

void DateTime::utcSec2timeStruct(TimeStruct *ts, time_t time)
{
    if (localtime_r(&time, ts) == 0)            // 0: can't compute
    {                                           // localtime returns dst info
        d_dstShift = 0;
        d_errno = errno;
        d_ok = false;
    }

    int dst;

    if (d_type == LOCALTIME)
    {
        dst = ts->tm_isdst;
        d_dstShift = dst == 1 ? 3600 : 0;
    }
    else
    {
        dst = 0;
        d_dstShift = 0;
    }

    time += d_displayZoneShift + d_dstShift; // add local time shift (if any)

    d_ok = gmtime_r(&time, ts);

    ts->tm_isdst = dst;
}
