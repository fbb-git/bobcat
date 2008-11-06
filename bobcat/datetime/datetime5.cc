#include "datetime.ih"

DateTime::DateTime(time_t time, int displayZoneShift, int utcZoneShift)
:
    d_type(-1),
    d_time(time)             // UTC is time + utcZoneShift
{
    initializeZones(displayZoneShift, utcZoneShift);
    breakDown();
}
