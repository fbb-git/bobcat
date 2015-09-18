#include "bigint.hh"

BigInt BigInt::isqrtc() const
{
    BigInt ret(*this);
    ret.isqrt();
    return ret;
}
