#include "bigint.hh"

BigInt BigInt::operator--(int)
{
    BigInt tmp(*this);
    --*this;
    return tmp;
}


