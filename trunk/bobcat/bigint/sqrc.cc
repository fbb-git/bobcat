#include "bigint.ih"

BigInt const BigInt::sqrc() const
{
    BigInt ret(*this);
    ret.sqr();
    return ret;
}
