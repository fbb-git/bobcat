#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  TimeType type, int utcZoneShift)
:
    d_type(type)
{
    istringstream in(timeStr);
    parse(in);              // determine timestruct representing LOCAL time

    if (d_ok)
    {
        zoneCorrection();
        initializeTime(d_time, utcZoneShift);

        setDisplayZone(0);
        utcSec2timeStruct(&d_tm, d_time);
    }
}
