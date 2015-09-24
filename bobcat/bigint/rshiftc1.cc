#include "bigint.ih"

BigInt BigInt::rshiftc() const
{
    BigInt ret(*this);
    ret.rshift();
    return ret;
}


