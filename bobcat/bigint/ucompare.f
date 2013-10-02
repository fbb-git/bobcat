inline int BigInt::uCompare(BigInt const &other) const
{
    return BN_ucmp(&d_bn, &other.d_bn);
}
