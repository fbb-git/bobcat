#include "datetime.ih"

bool DateTime::breakDown(time_t time, TimeStruct *ts)
{
    time += d_displayZoneShift;     // add local time (if any)

    return gmtime_r(&time, ts);
}
