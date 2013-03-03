#include "bigint.ih"

BigInt &BigInt::lshift(size_t nBits)
{
    if (!BN_lshift(&d_bn, &d_bn, nBits))
        throw Exception() << "BigInt::lshift(size_t) failed";

    return *this;
}


