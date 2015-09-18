#include "bigint.hh"

BigInt BigInt::rshiftc() const
{
    BigInt ret(*this);
    ret.rshift();
    return ret;
}


