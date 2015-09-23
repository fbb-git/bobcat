#include "bigint.hh"

BigInt &BigInt::operator%=(BigInt const &rhs)
{
    checked3(0, &d_bn, rhs, "%=");
    return *this;
}

