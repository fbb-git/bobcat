#include "datetime.ih"

DateTime::DateTime(time_t time, int displayOffset, int zoneShift)
:
    d_type(-1),
    d_time(time)             // UTC is time + zoneShift
{
    initializeZones(displayOffset, zoneShift);
    breakDown();
}
