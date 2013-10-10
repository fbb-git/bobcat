inline unsigned long BigInt::ulong() const
{
    return BN_get_word(&d_bn);
}
