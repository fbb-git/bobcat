#include "datetime.ih"

DateTime::DateTime(int displayZoneShift)
:
    d_type(LOCALTIME),
    d_time(::time(0))
{
    zoneCorrection();

    setDisplayZone(displayZoneShift);
    utcSec2timeStruct(&d_tm, d_time);
}
