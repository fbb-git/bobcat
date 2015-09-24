#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  int displayZoneShift)
:
    d_type(LOCALTIME)
{
    istringstream in(timeStr);
    parse(in);              // determine timestruct representing hour in UTC

    d_tm2d_tm(displayZoneShift);
}

