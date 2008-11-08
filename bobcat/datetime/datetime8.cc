#include "datetime.ih"

DateTime::DateTime(TimeStruct const *t, int displayZoneShift, int utcZoneShift)
:
    d_type(LOCALTIME),
    d_time(timeStruct2utcTime(ts)) 
{
    initializeTime(displayZoneShift, utcZoneShift);
    utcTime2timeStruct(&d_tm, time);
}
