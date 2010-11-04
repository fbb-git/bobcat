#include "bigint.ih"

BigInt const BigInt::tildeIntc() const
{
    BigInt ret(*this);
    ret.tildeInt();
    return ret;
}
