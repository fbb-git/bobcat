#include "bigint.ih"

BigInt const BigInt::gcdc(BigInt const &rhs) const
{
    BigInt ret(*this);
    ret.gcd(rhs);
    return ret;
}
