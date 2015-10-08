#include "bigint.ih"

BigInt::BigInt()
{
    BN_init(&d_bn);
}
