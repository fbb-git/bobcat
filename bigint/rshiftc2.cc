#include "bigint.hh"

BigInt BigInt::rshiftc(size_t nBits) const
{
    BigInt ret(*this);
    ret.rshift(nBits);
    return ret;
}
