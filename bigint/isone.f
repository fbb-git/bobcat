inline bool BigInt::isOne() const
{
    return BN_is_one(d_bn);
}
