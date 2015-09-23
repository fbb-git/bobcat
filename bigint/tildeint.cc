#include "bigint.hh"

// neg = toggle + 1 -> toggle = neg - 1

BigInt &BigInt::tildeInt()
{
    return --negate();
}

