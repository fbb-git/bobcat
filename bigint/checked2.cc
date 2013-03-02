#include "bigint.ih"

BigInt const BigInt::checked2(int (*BN_op)(BIGNUM *, BIGNUM const *, BIGNUM const *, 
                                     BIGNUM const *, BN_CTX *),
                        BigInt rhs, BigInt const &mod, char const *op) const
{
    BNCTX ctx;
    BigInt ret;

    if ((*BN_op)(&ret.d_bn, &d_bn, &rhs.d_bn, &mod.d_bn, ctx) != 1)
        throw Errno("BigInt ") << insertable << op << " failed" << throwable;

    return ret;
}
