#include "bigint.hh"

BigInt BigInt::tildeBitsc() const
{
    BigInt ret(*this);
    ret.tildeBits();
    return ret;
}
