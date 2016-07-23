#include "bigint.ih"

BigInt &BigInt::rshift(size_t nBits)
{
    if (!BN_rshift(this->d_bn, this->d_bn, nBits))
        throw Exception{} << "BigInt::rshift(size_t) failed";

    return *this;
}


