#include "bigint.hh"

BigInt BigInt::lshiftc() const
{
    BigInt ret(*this);
    ret.lshift();
    return ret;
}


