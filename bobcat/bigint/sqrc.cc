#include "bigint.hh"

BigInt BigInt::sqrc() const
{
    BigInt ret(*this);
    ret.sqr();
    return ret;
}
