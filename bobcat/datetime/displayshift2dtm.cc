#include "datetime.hh"

void DateTime::displayShift2d_tm()
{
    if (d_type == UTC)
    {
        d_dstShift = 0;
        setDisplayZone(0);
    }
    else
    {
        time_t shift = defaultDisplayZoneShift() + dstCorrection();
        d_utcSec -= shift;
        setDisplayZone(shift);
    }

    utcSec2timeStruct(&d_tm, d_utcSec);
}
