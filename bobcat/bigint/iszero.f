inline bool BigInt::isZero() const
{
    return BN_is_zero(&d_bn);
}
