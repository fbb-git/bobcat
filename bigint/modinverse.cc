#include "bigint.ih"

void BigInt::mod_inverse(BigInt *ret, BigInt const &mod) const
{
    BNCTX ctx;

    if (BN_mod_inverse(&ret->d_bn, &d_bn, &mod.d_bn, ctx) == 0)
        throw Errno("BigInt::inverseMod failed");
}
