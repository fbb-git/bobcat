#include "datetime.ih"

DateTime::DateTime(TimeType type)
:
    d_type(type),
    d_time(::time(0))
{
    breakDown(type);
}
