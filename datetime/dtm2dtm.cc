#include "datetime.ih"

void DateTime::d_tm2d_tm(int displayZoneShift)      // shift in minutes
{
    d_dstShift = 0;
    d_tm.tm_isdst = 0;

    d_tm2utcSec();          // UTC seconds matching d_tm in d_utcSec

    setDisplayZone(zoneShiftSeconds(displayZoneShift));
    utcSec2timeStruct(&d_tm, d_utcSec);
}
