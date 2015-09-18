#include "bigint.hh"

BigInt BigInt::setBitc(size_t index) const
{
    BigInt ret(*this);
    ret.setBit(index);
    return ret;
}
