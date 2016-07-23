#include "bigint.ih"

BigInt::Word BigInt::at(size_t index) const
{
    nWordsCheck(index);

    BigInt dest{*this};
    dest.rshift(index * BN_BYTES);
    return (dest &= BigInt{static_cast<size_t>(WordMask)}).ulong();
}
