#include "datetime.ih"

//     struct tm ts = {0, 0, 10, 5, 6, 109, 0, 0, 1};
//      dst and day-of-year fields ignored. With UTC ts represents UTC time
//      with LOCALTIME ts represents local time

DateTime::DateTime(TimeStruct const &ts, TimeType type)
:
    d_type(type)
{
    d_tm = ts;

    d_tm2timeType();
}
