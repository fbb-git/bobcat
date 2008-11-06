#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  int displayOffset, int zoneShift)
:
    d_type(-1)
{
    initializeZones(displayOffset, zoneShift);
    istringstream in(timeStr);
    parse(in);
}
