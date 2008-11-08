#include "datetime.ih"

time_t DateTime::timeStruct2utcSec(TimeStruct *ts) const 
{
    return mktime(ts) + s_zoneCorrection - d_displayZoneShift;
}
