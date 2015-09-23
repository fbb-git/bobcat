#include "bigint.hh"

BigInt::BigInt()
{
    BN_init(&d_bn);
}
