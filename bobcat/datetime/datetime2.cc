#include "datetime.ih"

DateTime::DateTime(int displayOffset)
:
    d_type(LOCALTIME),
    d_time(::time(0))
{
    initializeZones(displayOffset, 0);
    breakDown(d_type);
}
