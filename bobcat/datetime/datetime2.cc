#include "datetime.ih"

DateTime::DateTime(int displayZoneShift)
:
    d_type(LOCALTIME)
{
    zoneCorrection();

    initializeTime(::time(0), 0, 0);
    setDisplayZone(displayZoneShift);
    utcSec2timeStruct(&d_tm, d_time);
}
