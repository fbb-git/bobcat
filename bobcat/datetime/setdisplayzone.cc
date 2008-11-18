#include "datetime.ih"

// type is UTC: no zoneshift
// type is LOCALTIME:
//      if explicitly set: determine displayzoneshift
//      if implicitly set: use current time zone shift

void DateTime::setDisplayZone()
{
    d_displayZoneShift = 
        d_type == UTC ?
            0
        :    
            s_currentZoneCorrection;
}




