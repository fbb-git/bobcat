#include "datetime.ih"

bool DateTime::breakDown()
{
    d_ok = breakDown(&d_tm);
    d_errno = errno;

    return d_ok;
}
