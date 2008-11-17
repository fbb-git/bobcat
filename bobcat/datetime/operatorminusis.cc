#include "datetime.ih"

DateTime &DateTime::operator-=(TimeStruct const &fields)
{
    TimeStruct ts = fields;

    d_time -= mktime(&ts) + s_currentZoneCorrection;

    utcSec2timeStruct(&d_tm, d_time);
    return *this;
}
