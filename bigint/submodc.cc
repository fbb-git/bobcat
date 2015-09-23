#include "bigint.hh"

BigInt BigInt::subModc(BigInt const &rhs, BigInt const &mod) const
{
    BigInt ret(*this);
    ret.subMod(rhs, mod);
    return ret;
}

