#include "bigint.hh"

BigInt &BigInt::gcd(BigInt const &rhs)
{
    checked4(BN_gcd, rhs, "gcd");
    return *this;
}
