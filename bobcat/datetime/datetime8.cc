#include "datetime.ih"

DateTime::DateTime(tm const *t, int displayZoneShift, int utcZoneShift)
:
    d_type(-1),
    d_tm(*t)
{
    d_time = mktime(utcCorrection(d_tm));        // d_time in UTC
    initializeZones(displayZoneShift, utcZoneShift);
    breakDown();
}
