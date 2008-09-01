#include "onekey.ih"

void OneKey::verify() const
{
    s_ok = true;    // at least one OneKey has been verified

    if (d_err != 0)
        throw Errno(d_err, d_errMsg);
}
