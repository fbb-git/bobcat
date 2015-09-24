#include "bigint.ih"

BigInt BigInt::tildeIntc() const
{
    BigInt ret(*this);
    ret.tildeInt();
    return ret;
}
