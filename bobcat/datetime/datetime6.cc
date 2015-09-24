#include "datetime.ih"

//     struct tm ts = {0, 0, 10, 5, 6, 109, 0, 0, 1};
//      dst and day-of-year fields ignored.
//      ts represents UTC, displayZoneShift is added to obtain local time

DateTime::DateTime(TimeStruct const &ts, int displayZoneShift)
:
    d_type(LOCALTIME)
{
    d_tm = ts;
    d_tm2d_tm(displayZoneShift);
}
