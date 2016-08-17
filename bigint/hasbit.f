inline bool BigInt::hasBit(size_t index) const
{
    return BN_is_bit_set(this->d_bn, index);
}
