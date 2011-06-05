#include "bigint.ih"

BigInt BigInt::negatec() const
{
    BigInt ret(*this);
    ret.negate();
    return ret;
}

