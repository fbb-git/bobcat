#include "datetime.ih"

// type is UTC: no zoneshift
// type is LOCALTIME:
//      if explicitly set: determine displayzoneshift
//      if implicitly set: use current time zone shift

void DateTime::setDisplayZone(bool implicit, int displayZoneShift)
{
    if (d_type == UTC)
        d_displayZoneShift = 0;
    else 
        d_displayZoneShift = implicit ? 
                                s_currentZoneCorrection
                            :
                                displayZoneShift / 30 * 30 % (12 * 60) * 60;
//
//
//displayZoneShift)
//        d_displayZoneShift = displayZoneShift / 30 * 30 % (12 * 60) * 60;
//    else
//    {
//        TimeStruct ts;
//        d_displayZoneShift = d_time - mktime(gmtime_r(&d_time, &ts));
//    }
}




