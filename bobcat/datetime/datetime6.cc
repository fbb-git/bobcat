#include "datetime.ih"

DateTime::DateTime(TimeStruct const *ts, int displayZoneShift)
:
    d_type(LOCALTIME)
{
    zoneCorrection();

    d_tm = *ts;
    d_displayZoneShift = 0;
    d_time = timeStruct2utcSec(&d_tm);

    setDisplayZone(displayZoneShift);
    utcSec2timeStruct(&d_tm, d_time);
}
