#include "datetime.ih"

bool DateTime::utcSec2timeStruct(TimeStruct *ts, time_t time)
{
    time += d_displayZoneShift;     // add local time (if any)

    bool ok = gmtime_r(&time, ts);
    d_errno = errno;

    if (ok)
        d_dstShift = static_cast<TriVal>(ts->tm_isdst) == YES ? 3600 : 0;
    else
        d_dstShift = 0;

    if (d_dstShift)
    {
        time += 3600;
        gmtime_r(&time, ts);
    }

    return ok;
}
