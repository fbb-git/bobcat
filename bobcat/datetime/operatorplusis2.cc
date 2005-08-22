#include "datetime.ih"
#include <iostream>

DateTime &DateTime::operator+=(time_t seconds)
{
    d_time += seconds;
    breakDown(d_type);
    return *this;
}
