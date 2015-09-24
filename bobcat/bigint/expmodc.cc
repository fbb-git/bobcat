#include "bigint.ih"

BigInt BigInt::expModc(BigInt const &exponent, BigInt const &mod) const
{
    BigInt ret(*this);
    ret.expMod(exponent, mod);
    return ret;
}
