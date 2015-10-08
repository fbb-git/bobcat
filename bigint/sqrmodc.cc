#include "bigint.ih"

BigInt BigInt::sqrModc(BigInt const &mod) const
{
    BigInt ret(*this);
    ret.sqrMod(mod);
    return ret;
}
