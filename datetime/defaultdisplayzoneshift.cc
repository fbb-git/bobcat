#include "datetime.ih"

time_t DateTime::defaultDisplayZoneShift() const
{
    TimeStruct ts;
    return d_utcSec - mktime(gmtime_r(&d_utcSec, &ts));
}




