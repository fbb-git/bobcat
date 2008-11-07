#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  TimeType type, int utcZoneShift)
:
    d_type(type)
{
    initializeTime(0, utcZoneShift);
    istringstream in(timeStr);
    parse(in);
}
