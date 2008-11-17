#include "datetime.ih"

DateTime::DateTime(TimeType type)
:
    d_type(type),
    d_time(::time(0))
{
    zoneCorrection();

    setDisplayZone(0);                  // displayZoneCorrection for `type'
    utcSec2timeStruct(&d_tm, d_time);
}
