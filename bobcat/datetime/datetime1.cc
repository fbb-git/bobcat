#include "datetime.ih"

DateTime::DateTime(TimeType type)
:
    d_type(type)
{
    initializeTime(0, 0);
    breakDown();
}
