#include "datetime.ih"

void DateTime::utcSec2timeStruct(TimeStruct *ts, time_t time)
{
    if (localtime_r(&time, ts) == 0)            // 0: can't compute
    {                                           // localtime returns dst info
        d_dstShift = 0;
        d_errno = errno;
        d_ok = false;
    }

    d_dstShift = ts->tm_isdst == 1 ? 3600 : 0;

    time += d_displayZoneShift + d_dstShift; // add local time shift (if any)

    d_ok = gmtime_r(&time, ts);
}
