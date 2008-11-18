#include "datetime.ih"

DateTime::DateTime(TimeType type)
:
    d_type(type),
    d_time(::time(0))
{
    zoneCorrection();

    setDisplayZone();              // displayZoneCorrection for `type'
    utcSec2timeStruct(&d_tm, d_time);
}
