#include "datetime.ih"

DateTime::DateTime(tm const *t, int displayOffset, int zoneShift)
:
    d_type(-1),
    d_tm(*t)
{
    d_time = mktime(utcCorrection(d_tm));        // d_time in UTC
    initializeZones(displayOffset, zoneShift);
    breakDown();
}
