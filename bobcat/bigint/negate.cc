#include "bigint.hh"

BigInt &BigInt::negate()
{
    BN_set_negative(&d_bn, not isNegative());
    return *this;
}

