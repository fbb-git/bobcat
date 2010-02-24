#include "bigint.ih"

BigInt const BigInt::lshiftc(size_t nBits) const
{
    BigInt ret(*this);
    ret.lshift(nBits);
    return ret;
}


