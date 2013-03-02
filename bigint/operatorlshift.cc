#include "bigint.ih"

BigInt &BigInt::operator<<=(size_t nBits)
{
    if (!lshift(nBits))
        throw Errno(1, "BigInt: l-shift operation failed");
    return *this;
}
