#include "bigint.ih"

BigInt const BigInt::operator--(int)
{
    BigInt tmp(*this);
    --*this;
    return tmp;
}


