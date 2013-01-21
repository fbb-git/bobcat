#include "bigint.ih"

BigInt &BigInt::checked2(
                int (*BN_op)(BIGNUM *, BIGNUM const *, BIGNUM const *, 
                             BIGNUM const *, BN_CTX *),
                BigInt const &rhs, BigInt const &mod, 
                char const *op)
{
    BNCTX ctx;

    if ((*BN_op)(&d_bn, &d_bn, &rhs.d_bn, &mod.d_bn, ctx) != 1)
        throw Exception() << "BigInt " << op << " failed";

    return *this;
}
