#include "datetime.ih"

void DateTime::initializeTime(int displayZoneShift, int utcZoneShift)
{
    d_time += utcZoneShift / 30 * 30 % (12 * 60) * 60;  // time zones are
                                                        // multiples of 30'
    TimeStruct ts;

    if (d_type == UTC)
        d_displayZoneShift = 0;
    else if (displayZone)
        d_displayZoneShift = displayZoneShift / 30 * 30 % (12 * 60) * 60;
    else
    {
        d_displayZoneShift = d_time - mktime(gmtime_r(&d_time, &ts));
        if (static_cast<TriVal>(ts.tm_isdst) == YES)
            d_displayZoneShift += 3600;
    }
}




