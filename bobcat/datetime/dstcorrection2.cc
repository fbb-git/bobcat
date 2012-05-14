#include "datetime.ih"

int DateTime::dstCorrection(bool *ok) const
{
    TimeStruct ts;

    tzset();                // see the localtime_r manpage: tzset() required
    TimeStruct *ret =  localtime_r(&d_utcSec, &ts);

    if (not (*ok = ret))    // 0: can't compute
        return 0;

    return ts.tm_isdst == 1 ? 3600 : 0;
}
