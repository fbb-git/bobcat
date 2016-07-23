#include "bigint.ih"

BigInt::BigInt()
:
    d_bn(BN_new())
{
//    BN_init(d_bn);
}
