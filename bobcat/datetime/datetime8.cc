#include "datetime.ih"

DateTime::DateTime(tm *t, int displayOffset, int zoneShift)
:
    d_type(type),
    d_tm(*t)
{
    d_time(mktime(utcCorrection(d_tm)));        // d_time in UTC
    initializeZones(displayOffset, zoneShift);
    breakDown(type);
}
