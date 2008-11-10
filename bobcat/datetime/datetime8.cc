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
        zoneCorrection();

        d_time += utcZoneShift / 30 * 30 % (12 * 60) * 60;  // time zones are
                                                            // multiples of 30'
        setDisplayZone(displayZoneShift);
        utcSec2timeStruct(&d_tm, d_time);
    }
}

