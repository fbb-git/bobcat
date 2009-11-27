#include "bigint.ih"

BigInt const BigInt::lshiftc() const
{
    BigInt ret(*this);
    ret.lshift();
    return ret;
}


