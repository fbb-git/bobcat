#include "bigint.ih"

BigInt &BigInt::checked4(int (*BN_op)(BIGNUM *, 
                                     BIGNUM const *, BIGNUM const *, 
                                     BN_CTX *),
                        BigInt const &rhs, char const *op)
{
    BNCTX ctx;

    if ((*BN_op)(&d_bn, &d_bn, &rhs.d_bn, ctx) != 1)
        throw Exception() << "BigInt " << op << " failed";

    return *this;
}


