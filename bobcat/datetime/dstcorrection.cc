#include "datetime.ih"

int DateTime::dstCorrection()
{
    if (d_type == UTC)
        return d_dstShift = 0;

    bool ok;
    d_dstShift = dstCorrection(&ok);

    if (!ok)
    {                                           // localtime returns dst info
        d_errno = errno;
        d_ok = false;
    }

    return d_dstShift;
}
