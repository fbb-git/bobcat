inline size_t BigInt::size() const
{
    return BN_num_bits(&d_bn);
}
