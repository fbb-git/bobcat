#include "bigint.ih"

BigInt BigInt::exp(BigInt const &exponent) const
{
    BNCTX ctx;
    BigInt ret;

    if (!BN_exp(&ret.d_bn, &d_bn, &exponent.d_bn, ctx))
        throw Errno("BigInt exp() failed");

    return ret;
}
