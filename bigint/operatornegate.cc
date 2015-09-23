#include "bigint.hh"

BigInt BigInt::operator-() const
{
    BigInt tmp(*this);
    tmp.negate();
    return tmp;
}

