#include "bigint.ih"

BigInt::Bit::Bit(BigInt &bi, size_t idx)
:
    d_bi(bi),
    d_idx(idx)
{}

