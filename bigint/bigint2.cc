#include "bigint.ih"

BigInt::BigInt(BIGNUM const &bignum)
:
    d_bn(BN_new())
{
//    BN_init(d_bn);
    copy(d_bn, bignum);
}
