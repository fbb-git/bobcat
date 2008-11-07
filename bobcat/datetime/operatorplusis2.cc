#include "datetime.ih"

DateTime &DateTime::operator+=(time_t seconds)
{
    d_time += seconds;
    breakDown();
    return *this;
}
