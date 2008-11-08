#include "datetime.ih"

bool DateTime::breakDown()
{
    d_ok = breakDown(d_time, &d_tm);
    d_errno = errno;

    return d_ok;
}
