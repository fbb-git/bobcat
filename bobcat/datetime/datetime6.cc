#include "datetime.ih"

DateTime::DateTime(TimeStruct const *ts, TimeType type)
:
    d_type(type)
{
    zoneCorrection();
    initializeTime(::time(0), 0);

    d_tm = *ts;
    d_displayZoneShift = 0;
    d_time = timeStruct2utcSec(&d_tm);

    setDisplayZone(0);
    utcSec2timeStruct(&d_tm, d_time);
}
