#include "bigint.ih"

BigInt const BigInt::negatec() const
{
    BigInt ret(*this);
    ret.negate();
    return ret;
}

