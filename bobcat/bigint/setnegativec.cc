#include "bigint.ih"

BigInt const BigInt::setNegativec(bool negative) const
{
    BigInt ret(*this);
    ret.setNegative(negative);
    return ret;
}
