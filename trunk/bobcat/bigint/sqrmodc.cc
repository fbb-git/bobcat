#include "bigint.ih"

BigInt const BigInt::sqrModc(BigInt const &mod) const
{
    BigInt ret(*this);
    ret.sqrMod(mod);
    return ret;
}
