#include "datetime.hh"

DateTime::DateTime(time_t time, int displayZoneShift)
:
    d_type(LOCALTIME),
    d_utcSec(time),
    d_dstShift(0)
{
    setDisplayZone(zoneShiftSeconds(displayZoneShift));
    utcSec2timeStruct(&d_tm, d_utcSec);
}
