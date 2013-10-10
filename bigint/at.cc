#include "bigint.ih"

BigInt::Word BigInt::at(size_t index) const
{
    nWordsCheck(index);

    return d_bn.d[index];
}
