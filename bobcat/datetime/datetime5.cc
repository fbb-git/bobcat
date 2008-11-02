#include "datetime.ih"

DateTime::DateTime(time_t time, int displayOffset, int zoneShift)
:
    d_type(type),
    d_time(time),             // time in UTC
{
    initializeZones(displayOffset, zoneShift);
    breakDown(type);
}
