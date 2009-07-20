#include "bigint.ih"

BigInt const BigInt::sqr() const
{
    BNCTX ctx;
    BigInt ret;

    if (BN_sqr(&ret.d_bn, &d_bn, ctx) != 1)
        throw Errno("BigInt sqr() failed");

    return ret;
}
