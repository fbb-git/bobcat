inline int BigInt::compare(BigInt const &other) const
{
    return BN_cmp(d_bn, other.d_bn);
}
