#include "datetime.ih"

DateTime::DateTime(int displayOffset)
:
    d_type(-1),
    d_time(::time(0))
{
    initializeZones(displayOffset, 0);
    breakDown();
}
