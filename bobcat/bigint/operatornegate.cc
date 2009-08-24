#include "bigint.ih"

BigInt const BigInt::operator-() const
{
    BigInt tmp(*this);
    return tmp.negate();
}

