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

        d_time += utcZoneShift / 30 * 30 % (12 * 60) * 60;  // time zones are
                                                            // multiples of 30'
        setDisplayZone(0);
        utcSec2timeStruct(&d_tm, d_time);
    }
}
