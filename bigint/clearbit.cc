#include "bigint.ih"

BigInt &BigInt::clearBit(size_t index)
{
    BN_clear_bit(d_bn, index);
    return *this;
}

