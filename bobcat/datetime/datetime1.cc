#include "datetime.ih"

DateTime::DateTime(TimeType type)
:
    d_type(type)
{
    zoneCorrection();

    initializeTime(::time(0), 0);       // d_time in UTC
    setDisplayZone(0);                  // displayZoneCorrection for `type'

    utcSec2timeStruct(&d_tm, d_time);
}
