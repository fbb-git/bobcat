#include "bigint.ih"

BigInt const BigInt::tildeBitsc() const
{
    BigInt ret(*this);
    ret.tildeBits();
    return ret;
}
