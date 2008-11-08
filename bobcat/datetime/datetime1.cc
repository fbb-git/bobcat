#include "datetime.ih"

DateTime::DateTime(TimeType type)
:
    d_type(type)
{
    zoneCorrection();

    initializeTime(::time(0), 0, 0);
    setDisplayZone(0);
    utcSec2timeStruct(&d_tm, d_time);
}
