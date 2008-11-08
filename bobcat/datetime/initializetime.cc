#include "datetime.ih"

int DateTime::initializeTime(time_t seconds, 
                              int displayZoneShift, int utcZoneShift)
{
    d_time = seconds;
    d_displayZoneShift = displayZoneShift;
    return utcZoneShift / 30 * 30 % (12 * 60) * 60;  // time zones are
                                                     // multiples of 30'
}




