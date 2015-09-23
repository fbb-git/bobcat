#include "datetime.hh"

DateTime::DateTime(string const &timeStr,  TimeType type)
:
    d_type(type),
    d_displayZoneShift(0),
    d_dstShift(0)
{
    istringstream in(timeStr);
    parse(in);              // determine timestruct representing hour in UTC


    d_tm2timeType();
}

