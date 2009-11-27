#include "bigint.ih"

BigInt::BigInt(BigInt const &other)
{
    BN_init(&d_bn);
    copy(&d_bn, other.d_bn);
}
