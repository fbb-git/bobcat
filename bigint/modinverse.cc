#include "bigint.hh"

void BigInt::mod_inverse(BigInt *ret, BigInt const &mod) const
{
    BNCTX ctx;

    if (BN_mod_inverse(&ret->d_bn, &d_bn, &mod.d_bn, ctx) == 0)
        throw Exception() << "BigInt::inverseMod failed";
}
