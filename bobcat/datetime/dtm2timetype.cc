#include "datetime.hh"

void DateTime::d_tm2timeType()
{
    d_tm.tm_isdst = 0;
    d_tm2utcSec();

    displayShift2d_tm();

}
