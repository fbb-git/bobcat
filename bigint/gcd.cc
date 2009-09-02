#include "bigint.ih"

namespace FBB
{

BigInt const gcd(BigInt const &lhs, BigInt const &rhs)
{
    BigInt tmp(lhs);
    tmp.checked4(BN_gcd, rhs, "gcd");
    return tmp;
}

} // FBB
