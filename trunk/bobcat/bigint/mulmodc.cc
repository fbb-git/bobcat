#include "bigint.ih"

BigInt BigInt::mulModc(BigInt const &rhs, BigInt const &mod) const
{
    BigInt ret(*this);
    ret.mulMod(rhs, mod);
    return ret;
}

