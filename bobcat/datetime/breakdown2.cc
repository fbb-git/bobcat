#include "datetime.ih"

bool DateTime::breakDown(TimeStruct *ts)
{
    time_t time = d_time + d_displayZoneShift; // add local time (if available)

    return gmtime_r(&time, ts);
}
