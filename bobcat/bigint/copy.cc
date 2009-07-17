#include "bigint.ih"

void BigInt::copy(BIGNUM *lhs, BIGNUM const &rhs)
{
    if (!BN_copy(lhs, &rhs))
        d_msg = "BigInt: copying BigInt failed";
}
