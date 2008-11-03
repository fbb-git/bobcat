#include "datetime.ih"

DateTime::DateTime(time_t time, TimeType type)
:
    d_type(type),
    d_time(time)              // time in UTC
{
    initializeZones(0, 0);
    breakDown();
}
