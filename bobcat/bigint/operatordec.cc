#include "bigint.ih"

BigInt BigInt::operator--(int)
{
    BigInt tmp(*this);
    --*this;
    return tmp;
}


