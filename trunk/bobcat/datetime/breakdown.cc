#include "datetime.ih"

bool DateTime::breakDown(TimeType type)
{
    d_ok = breakDown(&d_tm, type, d_time);
    d_errno = errno;

    if (d_ok)
        d_timezone = timezone;

    return d_ok;
}
