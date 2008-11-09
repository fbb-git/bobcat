#include "datetime.ih"

DateTime::DateTime(time_t time, int displayZoneShift, int utcZoneShift)
:
    d_type(LOCALTIME)
{
    zoneCorrection();

    utcZoneShift = initializeTime(time, utcZoneShift);
    d_time += utcZoneShift;

    setDisplayZone(displayZoneShift);
    utcSec2timeStruct(&d_tm, d_time);
}
