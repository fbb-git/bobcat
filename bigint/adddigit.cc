#include "bigint.ih"

bool BigInt::addDigit(char ch, BigInt &ret, BigInt const &radix, 
                                            int (*pConv)(int))
{
    if (not (*pConv)(static_cast<unsigned char>(ch)))
        return true;        // true means: character outside of expected range
                            // which will end find_if.

    ret *= radix;
    ret += isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;

    return false;
}
