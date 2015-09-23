#include "bigint.hh"

BigInt BigInt::sqrModc(BigInt const &mod) const
{
    BigInt ret(*this);
    ret.sqrMod(mod);
    return ret;
}
