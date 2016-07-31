inline explicit BigInt::BigInt(BIGNUM *bignum)
:
    BigInt(const_cast<BIGNUM const *>(bignum))
{}
