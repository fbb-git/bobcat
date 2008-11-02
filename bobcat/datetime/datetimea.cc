#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  int displayOffset, int zoneShift)
:
    d_type(type),
{
    parse(timeStr);
    initializeZones(displayOffset, zoneShift);
    breakDown(type);
}
