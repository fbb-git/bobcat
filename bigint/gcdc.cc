#include "bigint.hh"

BigInt BigInt::gcdc(BigInt const &rhs) const
{
    BigInt ret(*this);
    ret.gcd(rhs);
    return ret;
}
