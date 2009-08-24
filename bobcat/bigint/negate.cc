#include "bigint.ih"

BigInt &BigInt::negate()
{
    BN_set_negative(&this->d_bn, not isNegative());
    return *this;
}

