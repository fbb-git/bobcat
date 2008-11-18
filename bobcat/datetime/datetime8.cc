#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  int displayZoneShift, 
                                           int utcZoneShift)
:
    d_type(LOCALTIME),
    d_dstShift(0)
{
cout << "datetime8\n";

    zoneCorrection();

    istringstream in(timeStr);
    parse(in);              // determine timestruct representing hour in UTC

    if (d_ok)
    {
        d_time += utcZoneShift / 30 * 30 % (12 * 60) * 60;  // time zones are
                                                            // multiples of 30'
        setDisplayZone(displayZoneShift);

cout << displayZoneShift << " " << d_displayZoneShift << endl;

        utcSec2timeStruct(&d_tm, d_time);
    }
}

