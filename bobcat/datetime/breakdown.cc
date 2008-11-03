#include "datetime.ih"

bool DateTime::breakDown()
{
    d_ok = breakDown(&d_tm);
    d_errno = errno;

    if (d_ok)
    {
        d_timezone = timezone;      // externally defined by, e.g. localtime()
        if (dst() == YES)
            d_timezone -= 3600;     // DST always adds one hour so
                                    // UTC - local time should subtract
                                    // another hour if DST is active. 
    }

    return d_ok;
}
