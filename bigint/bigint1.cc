#include "bigint.ih"

BigInt::BigInt()
:
    d_bn(BN_new())
{}
