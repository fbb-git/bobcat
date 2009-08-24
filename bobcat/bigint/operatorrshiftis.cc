#include "bigint.ih"

BigInt &BigInt::operator>>=(size_t nBits)
{
    if (!rshift(nBits))
        throw Errno(1, "BigInt: r-shift operation failed");
    return *this;
}
