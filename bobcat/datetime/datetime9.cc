#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  TimeType type, int zoneShift)
:
    d_type(type)
{
    initializeZones(0, zoneShift);
    istringstream in(timeStr);
    parse(in);
}
