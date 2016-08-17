#include "bigint.ih"

void BigInt::setWord(size_t index, BigInt::Word word)
{
    nWordsCheck(index);

    BigInt dest{rshiftc((index + 1) * BN_BYTES)};   // keep the most 
                                                    // significant part
    dest.rshift(8 * BN_BYTES);                      // make room for 'word'
    dest |= BigInt(word);                           // put 'word' at [0]
    if (index > 0)
    {
        dest.rshift(index * BN_BYTES);              // room for the least
                                                    // significant part (LSP)
        dest |= maskBits(index * BN_BYTES);         // put in the LSP
    }
    swap(dest);                                     // use the computed value
}
