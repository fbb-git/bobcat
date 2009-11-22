#include "bigint.ih"

BigInt const BigInt::inverseModc(BigInt const &mod) const
{
    BigInt ret(*this);
    mod_inverse(&ret, mod);
    return ret;
}
