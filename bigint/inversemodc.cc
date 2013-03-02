#include "bigint.ih"

BigInt BigInt::inverseModc(BigInt const &mod) const
{
    BigInt ret(*this);
    mod_inverse(&ret, mod);
    return ret;
}
