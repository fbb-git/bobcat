#include "datetime.ih"

void DateTime::d_tm2utcSec()
{
    d_utcSec = timeStruct2utcSec(&d_tm);
    d_utcSec += defaultDisplayZoneShift();
}
