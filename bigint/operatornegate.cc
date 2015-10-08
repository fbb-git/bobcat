#include "bigint.ih"

BigInt BigInt::operator-() const
{
    BigInt tmp(*this);
    tmp.negate();
    return tmp;
}

