#include "bigint.ih"

BigInt::BigInt(BIGNUM const &bignum)
{
    BN_init(&d_bn);
    copy(&d_bn, bignum);
}
