#include "bigint.ih"

BigInt &BigInt::setNegative(bool negative)
{
    BN_set_negative(d_bn, negative);
    return *this;
}

