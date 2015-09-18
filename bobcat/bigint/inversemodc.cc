#include "bigint.hh"

BigInt BigInt::inverseModc(BigInt const &mod) const
{
    BigInt ret(*this);
    mod_inverse(&ret, mod);
    return ret;
}
