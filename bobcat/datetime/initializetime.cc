#include "datetime.ih"

int DateTime::initializeTime(time_t seconds, int utcZoneShift)
{
    d_time = seconds;
    utcZoneShift = utcZoneShift / 30 * 30 % (12 * 60) * 60;// time zones are
                                                           // multiples of 30'

    d_time += utcZoneShift;
    return utcZoneShift;
}




