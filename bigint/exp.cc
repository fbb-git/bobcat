#include "bigint.hh"

BigInt &BigInt::exp(BigInt const &exponent)
{
    BNCTX ctx;

    if (!BN_exp(&d_bn, &d_bn, &exponent.d_bn, ctx))
        throw Exception() << "BigInt exp() failed";

    return *this;
}
