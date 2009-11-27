#include "bigint.ih"

BigInt const BigInt::rshiftc(size_t nBits) const
{
    BigInt ret(*this);
    ret.rshift(nBits);
    return ret;
}
