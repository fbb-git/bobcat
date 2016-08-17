inline size_t BigInt::nWords() const
{
    return (size() + BN_BYTES - 1) / BN_BYTES;
}
