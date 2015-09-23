#include "bigint.hh"

BigInt &BigInt::operator*=(BigInt const &rhs)
{
    BNCTX ctx;

    if (BN_mul(&d_bn, &d_bn, &rhs.d_bn, ctx) == 0)
        throw Exception() << "BigInt *= failed";

    return *this;
}
