#include "datetime.ih"

DateTime::DateTime(time_t time, int displayZoneShift)
:
    d_type(LOCALTIME),
    d_time(time)
{
    zoneCorrection();

    setDisplayZone(displayZoneShift);
    utcSec2timeStruct(&d_tm, d_time);
}
