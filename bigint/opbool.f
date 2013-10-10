inline BigInt::Bit::operator bool() const
{
    return d_bi.hasBit(d_idx);
}
