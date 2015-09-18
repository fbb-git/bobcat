#include "datetime.hh"

void DateTime::setDisplayZone(time_t displayZoneShift)
{
    d_displayZoneShift = (d_type == UTC) ? 0 : displayZoneShift;
}




