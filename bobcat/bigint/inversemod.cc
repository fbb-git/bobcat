#include "bigint.ih"

namespace FBB
{

BigInt const inverseMod(BigInt const &lhs, BigInt const &mod)
{
    BNCTX ctx;
    BigInt ret;

    if (BN_mod_inverse(&ret.d_bn, &lhs.d_bn, &mod.d_bn, ctx) == 0)
        throw Errno("BigInt::inverseMod failed");

    return ret;
}

} // FBB
