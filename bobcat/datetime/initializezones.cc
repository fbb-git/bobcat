#include "datetime.ih"

void DateTime::initializeZones(int displayZone, int zoneShift)
{
    d_zoneShift = zoneShift / 30 * 30 % (12 * 60);    // time zones are
                                                        // multiples of 30'
    switch (d_type)
    {
        LOCALTIME:              // see driver/demos/localtime.cc
            d_displayZone = time(0);
            d_displayZone -= mktime(gmtime(&utc));
        break;

        UTC:                    // UTC: no shift
            d_displayZone = 0;
        break;
    
        default:                // user specified: ensure correct range
                                // and multiple of 30'
            d_displayZone = displayZone / 30 * 30 % (12 * 60);
        break;
    }
}
