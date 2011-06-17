#include "bigint.ih"

BigInt BigInt::expc(BigInt const &exponent) const
{
    BigInt ret(*this);
    ret.exp(exponent);
    return ret;
}
