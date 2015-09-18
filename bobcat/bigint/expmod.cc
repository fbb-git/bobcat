#include "bigint.hh"

BigInt &BigInt::expMod(BigInt const &exponent, BigInt const &mod)
{
    BNCTX ctx;

    if (BN_mod_exp(&d_bn, &d_bn, &exponent.d_bn, &mod.d_bn, ctx) == 0)
    throw Exception() << "BigInt sqr() failed";

    return *this;
}
