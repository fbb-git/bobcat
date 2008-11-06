#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  int displayZoneShift, int utcZoneShift)
:
    d_type(-1)
{
    initializeZones(displayZoneShift, utcZoneShift);
    istringstream in(timeStr);
    parse(in);
}
