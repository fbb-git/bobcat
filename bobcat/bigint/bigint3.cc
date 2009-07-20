#include "bigint.ih"

BigInt::BigInt(BigInt const &other)
{
    BN_init(&d_bn);
    copy(other);
}
