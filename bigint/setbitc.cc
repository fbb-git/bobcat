#include "bigint.ih"

BigInt const BigInt::setBitc(size_t index) const
{
    BigInt ret(*this);
    ret.setBit(index);
    return ret;
}
