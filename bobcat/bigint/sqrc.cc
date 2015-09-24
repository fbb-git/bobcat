#include "bigint.ih"

BigInt BigInt::sqrc() const
{
    BigInt ret(*this);
    ret.sqr();
    return ret;
}
