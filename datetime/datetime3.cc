#include "datetime.ih"

// time represents UTC or LOCALTIME
// For time == LOCALTIME: LOCALTIME = UTC + TZ + dst -> UTC = time - TZ - dst

DateTime::DateTime(time_t time, TimeType type)
:
    d_type(type),
    d_utcSec(time)
{
    displayShift2d_tm();
}
