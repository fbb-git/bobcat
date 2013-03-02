#include "bigint.ih"

BigInt &BigInt::sqr()
{
    BNCTX ctx;

    if (BN_sqr(&d_bn, &d_bn, ctx) != 1)
        throw Errno("BigInt sqr() failed");

    return *this;
}
