#include "bigint.ih"

BigInt BigInt::isqrtc() const
{
    BigInt ret(*this);
    ret.isqrt();
    return ret;
}
