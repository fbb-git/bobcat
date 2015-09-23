#include "datetime.hh"

DateTime &DateTime::operator+=(time_t seconds)
{
    d_utcSec += seconds;
    utcSec2timeStruct(&d_tm, d_utcSec);
    return *this;
}
