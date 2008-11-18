#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  TimeType type, int utcZoneShift)
:
    d_type(type),
    d_dstShift(0)
{
cout << "datetime9\n";
    zoneCorrection();

    istringstream in(timeStr);
    parse(in);              // determine timestruct representing hour in UTC

    if (d_ok)
    {
        d_time += utcZoneShift / 30 * 30 % (12 * 60) * 60;  // time zones are
                                                            // multiples of 30'
        setDisplayZone(0);
        utcSec2timeStruct(&d_tm, d_time);
    }
}
