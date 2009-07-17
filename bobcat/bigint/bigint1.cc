#include "bigint.ih"

BigInt::BigInt()
:
    d_msg(0)
{
    BN_init(&d_bn);
}
