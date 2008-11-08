#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  TimeType type, int utcZoneShift)
:
    d_type(type)
{
    istringstream in(timeStr);
    parse(in);
    if (d_ok)
    {
        d_time = timeStruct2utcSec(&d_tm);
        initializeTime(0, utcZoneShift);
        utcSec2timeStruct(&d_tm, d_time);
    }
}
