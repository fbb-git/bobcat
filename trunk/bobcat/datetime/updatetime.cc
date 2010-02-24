#include "datetime.ih"

bool DateTime::updateTime(TimeStruct &tm)
{
    if (!d_ok)
        return false;

    time_t utcSec = d_utcSec;
    TimeStruct dtm = d_tm;
    int dspShift = d_displayZoneShift;  // this also allows for DST

    d_tm = tm;

    d_tm.tm_sec -= dspShift;        // tm back to UTC
    d_tm2d_tm(dspShift / 60);       // add the display shift for loc. time

    if (d_ok)
    {
        if (dstCorrection())
            d_tm.tm_isdst = 1;
        d_dstShift = 0;
    }
    else
    {
        d_utcSec = utcSec;
        d_tm = dtm;
        d_displayZoneShift = dspShift;

    }

    return d_ok;
}
