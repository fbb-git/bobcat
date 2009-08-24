#include "bigint.ih"

BigInt &BigInt::setNegative(bool negative)
{
    BN_set_negative(&this->d_bn, negative);
    return *this;
}

