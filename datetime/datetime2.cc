#include "datetime.hh"

// UTC + displayZoneShift = LOCALTIME

DateTime::DateTime(int displayZoneShift)
:
    d_type(LOCALTIME),
    d_utcSec(::time(0)),
    d_dstShift(0)
{
    setDisplayZone(zoneShiftSeconds(displayZoneShift));
    utcSec2timeStruct(&d_tm, d_utcSec);
}



