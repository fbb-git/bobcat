#include "datetime.ih"

DateTime::DateTime(TimeType type)
:
    d_type(type),
    d_time(::time(0))
{
    initializeTime(0, 0);
    breakDown();
}
