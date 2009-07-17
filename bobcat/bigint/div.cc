#include "bigint.ih"

BigInt BigInt::div(BigInt *remainder, BigInt const &rhs) const
{
    BigInt ret(*this);
    ret.verify();

    checked3(&ret.d_bn, &remainder->d_bn, rhs, "div");
    return ret;
}

