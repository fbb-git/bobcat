#include "bigint.ih"

BigInt::BigInt(BigInt const &other)
:
    d_msg(0)
{
    BN_init(&d_bn);
    copy(other);
}
