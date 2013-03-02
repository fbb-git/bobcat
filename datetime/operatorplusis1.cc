#include "datetime.ih"

DateTime &DateTime::operator+=(time_t seconds)
{
    d_time += seconds;
    utcSec2timeStruct(&d_tm, d_time);
    return *this;
}
