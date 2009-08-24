#include "bigint.ih"

// neg = toggle + 1 -> toggle = neg - 1


BigInt const BigInt::tildeInt() const
{
    BigInt tmp(*this);

    tmp.negate();
    --tmp;
    return tmp;
}

