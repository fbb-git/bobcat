#include "bigint.ih"

BigInt &BigInt::setBit(size_t index)
{
    if (!BN_set_bit(this->d_bn, index))
        throw Exception{} << "BigInt::setBit failed";

    return *this;
}

