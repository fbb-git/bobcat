inline bool BigInt::isOdd() const
{
    return BN_is_odd(&d_bn);
}
