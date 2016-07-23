#include "bigint.ih"

BigInt BigInt::divc(BigInt *remainder, BigInt const &rhs) const
{
    BigInt ret(*this);
    checked3(ret.d_bn, remainder->d_bn, rhs, "div");
    return ret;
}

