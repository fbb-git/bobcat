#include "datetime.ih"

bool DateTime::breakDown(TimeType type)
{
    d_ok = type == LOCALTIME ?
                localtime_r(&d_time, &d_tm)
            :
                gmtime_r(&d_time, &d_tm);

    d_errno = errno;

    return d_ok;
}
