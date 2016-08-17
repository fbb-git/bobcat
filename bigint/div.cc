#include "bigint.ih"

BigInt &BigInt::div(BigInt *remainder, BigInt const &rhs)
{
    checked3(d_bn, remainder->d_bn, rhs, "div");
    return *this;
}

