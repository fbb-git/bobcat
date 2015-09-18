#include "bigint.hh"

BigInt BigInt::clearBit(size_t index) const
{
    BigInt ret(*this);
    BN_clear_bit(&ret.d_bn, index);
    return ret;
}

