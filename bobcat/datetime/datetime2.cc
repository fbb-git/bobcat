#include "datetime.ih"

DateTime::DateTime(int displayZoneShift)
:
    d_type(LOCALTIME),
    d_time(::time(0))
{
    initializeTime(displayZoneShift, 0);
    breakDown();
}
