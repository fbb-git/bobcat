#include "bigint.ih"

BigInt::BigInt(BIGNUM const *bignum)
:
    d_bn(BN_new())
{
    copy(d_bn, *bignum);
}
