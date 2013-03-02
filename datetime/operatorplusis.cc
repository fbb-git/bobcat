#include "datetime.ih"

DateTime &DateTime::operator+=(DateTime const &other)
{
    d_time += other.d_time;
    breakDown(d_type = UTC);
    return *this;
}
