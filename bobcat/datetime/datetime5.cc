#include "datetime.ih"

DateTime::DateTime(time_t time, int displayZoneShift, int utcZoneShift)
:
    d_type(LOCALTIME)
{
    zoneCorrection();
    initializeTime(time, utcZoneShift);

    setDisplayZone(displayZoneShift);
    utcSec2timeStruct(&d_tm, d_time);
}
