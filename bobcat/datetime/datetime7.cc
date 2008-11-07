#include "datetime.ih"

DateTime::DateTime(TimeStruct const *ts, TimeType type, int utcZoneShift)
:
    d_type(type),
    d_time(utcCorrection(ts))
{
    initializeTime(0, utcZoneShift);
    breakDown();
}
