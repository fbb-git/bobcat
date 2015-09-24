#include "datetime.ih"

bool DateTime::setTime(time_t seconds)
{
    time_t utc = d_utcSec;
    TimeStruct ts = d_tm;

    d_utcSec = seconds;

    if (d_type == UTC)
        displayShift2d_tm();
    else
    {
        d_dstShift = 0;
        d_utcSec -= d_displayZoneShift;
        utcSec2timeStruct(&d_tm, d_utcSec);
    }

    if (!d_ok)
    {
        d_utcSec = utc;
        d_tm = ts;
    }
    return d_ok;
}
