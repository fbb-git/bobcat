#include "bigint.hh"

char *BigInt::bn2oct(BIGNUM const *bn)
{
    size_t nBits = (((BN_num_bits(bn)) + 2) / 3) * 3;

    char *ret = new char[nBits + 3];        // 1 for the -, 1 for the 0
                                            // 1 for the asciiZ
    char *cp = ret;
    
    if (BN_is_negative(bn))
        *cp++ = '-';

    *cp++ = '0';                            // initial 0 indicating octal

    for (; nBits; )                         // proceed until 1st value != 0
    {
        nBits -= 3;

        if (int value = (BN_is_bit_set(bn, nBits + 2) << 2) +
                        (BN_is_bit_set(bn, nBits + 1) << 1) +
                         BN_is_bit_set(bn, nBits))
        {
            *cp++ = '0' + value;
            break;
        }
    }

    for (; nBits; )                         // do the rest
    {
        nBits -= 3;

        *cp++ = '0' + (BN_is_bit_set(bn, nBits + 2) << 2) +
                      (BN_is_bit_set(bn, nBits + 1) << 1) +
                       BN_is_bit_set(bn, nBits);
    }

    *cp = 0;

    return ret;    
}
