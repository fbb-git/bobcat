#include "bigint.ih"

BigInt BigInt::setNegativec(bool negative) const
{
    BigInt ret(*this);
    ret.setNegative(negative);
    return ret;
}
