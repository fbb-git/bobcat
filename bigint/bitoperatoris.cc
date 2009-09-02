#include "bigint.ih"

BigInt::Bit &BigInt::Bit::operator=(bool rhs)
{
    d_bi.setBit(d_idx, rhs);
    return *this;
}

