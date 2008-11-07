#include "datetime.ih"

DateTime::DateTime(TimeStruct const *t, int displayZoneShift, int utcZoneShift)
:
    d_type(LOCALTIME),
    d_time(utcCorrection(ts))
{
    initializeTime(displayZoneShift, utcZoneShift);
    breakDown();
}
