#include "datetime.ih"

bool DateTime::breakDown(TimeType type)
{
    d_ok = breakDown(&d_tm, type, d_time);
    d_errno = errno;

    return d_ok;
}
