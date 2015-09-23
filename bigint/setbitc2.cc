#include "bigint.hh"

BigInt BigInt::setBitc(size_t index, bool value) const
{
    BigInt ret(*this);
    ret.setBit(index, value);
    return ret;
}
