#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  int displayZoneShift, 
                                           int utcZoneShift)
:
    d_type(LOCALTIME)
{
    initializeTime(displayZoneShift, utcZoneShift);
    istringstream in(timeStr);
    parse(in);
}
