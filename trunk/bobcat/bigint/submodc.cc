#include "bigint.ih"

BigInt const BigInt::subModc(BigInt const &rhs, BigInt const &mod) const
{
    BigInt ret(*this);
    ret.subMod(rhs, mod);
    return ret;
}

