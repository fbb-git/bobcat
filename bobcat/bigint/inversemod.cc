#include "bigint.ih"

BigInt const BigInt::inverseMod(BigInt const &mod) const
{
    BNCTX ctx;
    BigInt ret;

    if (BN_mod_inverse(&ret.d_bn, &d_bn, &mod.d_bn, ctx) == 0)
        throw Errno("BigInt::inverseMod failed");

    return ret;
}
