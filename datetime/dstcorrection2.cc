#include "datetime.ih"

int DateTime::dstCorrection(bool *ok) const
{
    TimeStruct ts;
    TimeStruct *ret =  localtime_r(&d_utcSec, &ts);

    if (ret == 0)    // 0: can't compute
        return 0;

    return ts.tm_isdst == 1 ? 3600 : 0;
}
