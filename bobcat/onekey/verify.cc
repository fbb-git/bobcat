#include "onekey.ih"

void OneKey::verify() const
{
    if (d_err)
        throw Errno(d_err, d_msg);
}
