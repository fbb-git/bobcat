#include "bigint.ih"

BigInt const BigInt::operator~() const
{
    BigInt tmp(*this);
    tmp.negate();
    --tmp;
    return tmp;
}
