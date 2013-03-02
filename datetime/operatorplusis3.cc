#include "datetime.ih"

DateTime &DateTime::operator+=(tm const &fields)
{
    tm work = fields;
    d_time += mktime(&work);
    breakDown(d_type);
    return *this;
}
