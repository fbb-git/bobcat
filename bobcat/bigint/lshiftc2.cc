#include "bigint.hh"

BigInt BigInt::lshiftc(size_t nBits) const
{
    BigInt ret(*this);
    ret.lshift(nBits);
    return ret;
}


