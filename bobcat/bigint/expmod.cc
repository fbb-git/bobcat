#include "bigint.ih"

BigInt BigInt::expMod(BigInt const &exponent, BigInt const &mod) const
{
    BNCTX ctx;
    BigInt ret;

    if (BN_mod_exp(&ret.d_bn, &d_bn, &exponent.d_bn, &mod.d_bn, ctx) == 0)
    throw Errno("BigInt sqr() failed");

    return ret;
}
