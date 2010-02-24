#include "bigint.ih"

BigInt const BigInt::rshiftc() const
{
    BigInt ret(*this);
    ret.rshift();
    return ret;
}


