inline size_t BigInt::sizeInBytes() const
{
    return BN_num_bytes(d_bn);
}
