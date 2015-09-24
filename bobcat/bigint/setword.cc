#include "bigint.ih"

void BigInt::setWord(size_t index, BigInt::Word word)
{
    nWordsCheck(index);

    d_bn.d[index] = word;
}
