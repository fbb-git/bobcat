#include "datetime.ih"

DateTime::DateTime(time_t time, TimeType type, int utcZoneShift)
:
    d_type(type)
{
    zoneCorrection();

    utcZoneShift = initializeTime(time, utcZoneShift);
    d_time += utcZoneShift;

    setDisplayZone(0);
    utcSec2timeStruct(&d_tm, d_time);
}
