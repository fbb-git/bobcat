#include "datetime.ih"

void DateTime::setDisplayZone(int displayZoneShift)
{
    d_displayZoneShift = displayZoneShift / 30 * 30 % (12 * 60) * 60;
}




