#include "datetime.ih"

bool DateTime::updateTime(TimeStruct &tm)
{
    if (!d_ok)
        return false;

    time_t utcSec = d_utcSec;
    TimeStruct dtm = d_tm;
    int dspShift = d_displayZoneShift;

    d_tm = tm;

    d_tm.tm_sec -= dspShift;        // tm back to UTC
    d_tm2d_tm(dspShift / 60);       // add the display shift for loc. time

    if (!d_ok)
    {
        d_utcSec = utcSec;
        d_tm = dtm;
        d_displayZoneShift = dspShift;
    }

    return d_ok;
}
