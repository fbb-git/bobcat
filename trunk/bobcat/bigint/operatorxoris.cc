#include "bigint.ih"

BigInt &BigInt::operator^=(BigInt const &rhs)
{
    setNegative(isNegative() ^ rhs.isNegative());
    
    size_t nMin = min(sizeInBytes(), rhs.sizeInBytes());
    size_t nMax = max(sizeInBytes(), rhs.sizeInBytes());

    unsigned char small[nMin];
    unsigned char large[nMax];

    BIGNUM const *bSmall;
    BIGNUM const *bLarge;

    if (sizeInBytes() < rhs.sizeInBytes())
    {
        bSmall = &d_bn;
        bLarge = &rhs.d_bn;
    }
    else
    {
        bLarge = &d_bn;
        bSmall = &rhs.d_bn;
    }
    
    BN_bn2bin(bSmall, small);    
    BN_bn2bin(bLarge, large);    

    unsigned char *largePtr = large + nMax - nMin;

    for (size_t idx = 0; idx != nMin; ++idx)        // XOR bytes 0 to nMin
        largePtr[idx] ^= small[idx];

    BN_bin2bn(large, nMax, &d_bn);

    return *this;
}
