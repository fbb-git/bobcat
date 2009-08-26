#include "bigint.ih"

BigInt &BigInt::setBit(size_t index)
{
    if (!BN_set_bit(&this->d_bn, index))
        throw Errno("BigInt::setBit failed");

    return *this;
}

