#include "bigint.ih"

void BigInt::verify() const
{
    if (d_msg)
        throw Errno(1, d_msg);
}
