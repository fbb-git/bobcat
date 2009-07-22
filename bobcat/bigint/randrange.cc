#include "bigint.ih"

BigInt const BigInt::randRange(BigInt const &max)
{
    BigInt ret;
    if (BN_rand_range(&ret.d_bn, const_cast<BIGNUM *>(&max.d_bn)) != 1)
        throw Errno("BigInt::randRange() failed");
    return ret;
}
