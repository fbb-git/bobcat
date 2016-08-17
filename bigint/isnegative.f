inline bool BigInt::isNegative() const
{
    return BN_is_negative(this->d_bn);
}
