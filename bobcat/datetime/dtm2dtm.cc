#include "datetime.ih"

void DateTime::d_tm2d_tm(int displayZoneShift)
{
    d_dstShift = 0;
    d_tm.tm_isdst = 0;

    d_tm2utcSec();

    setDisplayZone(zoneShiftSeconds(displayZoneShift));
    utcSec2timeStruct(&d_tm, d_utcSec);
}
