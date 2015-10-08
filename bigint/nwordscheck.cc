#include "bigint.ih"

void BigInt::nWordsCheck(size_t index) const
{
    if (index >= nWords())
        throw Exception() << "BigInt: word index " << index << " exceeds " << 
                                                                    nWords();
}
