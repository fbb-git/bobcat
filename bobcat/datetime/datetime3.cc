#include "datetime.ih"

DateTime::DateTime(tm *t, TimeType type)
:
    d_type(type),
    d_time(mktime(t))
{
    breakDown(type);
}
