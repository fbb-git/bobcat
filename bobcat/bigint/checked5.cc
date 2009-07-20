#include "bigint.ih"

BigInt const BigInt::checked5(BIGNUM *(*BN_op)(BIGNUM *, 
                                     BIGNUM const *, BIGNUM const *, BN_CTX *),
                        BigInt const &mod, char const *op) const
{
    BNCTX ctx;
    BigInt ret;

    if ((*BN_op)(&ret.d_bn, &d_bn, &mod.d_bn, ctx) == 0)
        throw Errno("BigInt ") << insertable << op << " failed" << throwable;

    return ret;
}


