#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  int displayZoneShift, 
                                           int utcZoneShift)
:
    d_type(LOCALTIME)
{
    istringstream in(timeStr);
    parse(in);
    if (d_ok)
    {
        d_time = timeStruct2utcSec(&d_tm);
        initializeTime(displayZoneShift, utcZoneShift);
        utcSec2timeStruct(&d_tm, d_time);
    }
}
