#include "bigint.hh"

BigInt &BigInt::operator/=(BigInt const &rhs)
{
    checked3(&d_bn, 0, rhs, "/=");
    return *this;
}

