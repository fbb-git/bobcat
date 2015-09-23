#include "bigint.hh"

BigInt::Bit &BigInt::Bit::operator^=(bool rhs)
{
    d_bi.setBit(d_idx, rhs ^ d_bi.hasBit(d_idx));
    return *this;
}

