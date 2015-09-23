#include "bigint.hh"

BigInt BigInt::negatec() const
{
    BigInt ret(*this);
    ret.negate();
    return ret;
}

