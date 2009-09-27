#include "bigint.ih"

BigInt const BigInt::gcd(BigInt const &rhs) const
{
    BigInt tmp(*this);
    tmp.checked4(BN_gcd, rhs, "gcd");
    return tmp;
}
