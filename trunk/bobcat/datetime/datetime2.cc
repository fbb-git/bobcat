#include "datetime.ih"

DateTime::DateTime(time_t time, TimeType type)
:
    d_type(type),
    d_time(time)
{
    breakDown(type);
}
