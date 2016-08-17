#include "bigint.ih"

void BigInt::copy(BIGNUM *lhs, BIGNUM const &rhs)
{
    if (!BN_copy(lhs, &rhs))
        throw Exception{} << "BigInt: copying BigInt failed";
}
