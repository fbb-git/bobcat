#include "datetime.ih"

DateTime::DateTime(TimeStruct const *ts, int displayZoneShift, 
                                         int utcZoneShift)
:
    d_type(LOCALTIME)
{
    zoneCorrection();
    utcZoneShift = initializeTime(::time(0), utcZoneShift);

    d_tm = *ts;
    d_displayZoneShift = 0;
    d_time = timeStruct2utcSec(&d_tm) + utcZoneShift;

    setDisplayZone(displayZoneShift);
    utcSec2timeStruct(&d_tm, d_time);
}
