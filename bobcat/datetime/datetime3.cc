#include "datetime.ih"

DateTime::DateTime(time_t time, TimeType type)
:
    d_type(type),
    d_time(time)
{
    zoneCorrection();

    setDisplayZone(0);
    utcSec2timeStruct(&d_tm, d_time);
}
