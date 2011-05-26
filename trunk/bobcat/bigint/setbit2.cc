#include "bigint.ih"

BigInt &BigInt::setBit(size_t index, bool value)
{
    return value ? setBit(index) : clearBit(index);    
}

