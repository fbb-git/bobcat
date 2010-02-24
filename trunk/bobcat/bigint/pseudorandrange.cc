#include "bigint.ih"

BigInt const BigInt::pseudoRandRange(BigInt const &max)
{
    BigInt ret;
    if (BN_pseudo_rand_range(&ret.d_bn, const_cast<BIGNUM *>(&max.d_bn)) != 1)
        throw Errno("BigInt::pseudoRandRange() failed");
    return ret;
}
