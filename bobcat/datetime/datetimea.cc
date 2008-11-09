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
        initializeTime(d_time, utcZoneShift);
    
        setDisplayZone(displayZoneShift);
        utcSec2timeStruct(&d_tm, d_time);
    }
}

