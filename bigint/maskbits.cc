#include "bigint.hh"

BigInt &BigInt::maskBits(size_t lowerNBits)
{
    if (!BN_mask_bits(&d_bn, lowerNBits))
        throw Exception() << "BigInt::maskBits failed";
    return *this;
}

