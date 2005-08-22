#include "datetime.ih"
#include <iostream>

DateTime &DateTime::operator+=(tm const &fields)
{
    tm work = fields;
    d_time += mktime(&work);
    breakDown(d_type);
    return *this;
}
