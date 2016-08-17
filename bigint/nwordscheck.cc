#include "bigint.ih"

void BigInt::nWordsCheck(size_t index) const
{
    size_t count;
    if (index >= (count = nWords()))
        throw Exception{} << "BigInt: word index " << index << " exceeds " << 
                                                                        count;
}
