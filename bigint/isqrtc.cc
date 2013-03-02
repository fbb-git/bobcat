#include "bigint.ih"

BigInt const BigInt::isqrtc() const
{
    BigInt ret(*this);
    ret.isqrt();
    return ret;
}
