#include "bigint.ih"

BigInt const BigInt::operator--(int) const
{
    BigInt tmp(*this);
    --tmp;
    return tmp;
}


