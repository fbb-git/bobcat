#include "datetime.ih"

DateTime::DateTime(time_t time, int displayZoneShift, int utcZoneShift)
:
    d_type(LOCALTIME),
    d_time(time)             // UTC is time + utcZoneShift
{
    initializeTime(displayZoneShift, utcZoneShift);
    utcTime2timeStruct(&d_tm, time);
}
