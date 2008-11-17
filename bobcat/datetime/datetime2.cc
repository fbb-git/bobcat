#include "datetime.ih"

DateTime::DateTime(int displayZoneShift)
:
    d_type(LOCALTIME),
    d_time(::time(0))
{
    zoneCorrection();

    setDisplayZone(displayZoneShift);
    d_ok = utcSec2timeStruct(&d_tm, d_time);
}
