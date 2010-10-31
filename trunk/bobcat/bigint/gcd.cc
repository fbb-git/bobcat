#include "bigint.ih"

BigInt &BigInt::gcd(BigInt const &rhs)
{
    checked4(BN_gcd, rhs, "gcd");
    return *this;
}
