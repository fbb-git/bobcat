#include "bigint.ih"

BigInt::BigInt(BigInt const &other)
:
    d_bn(BN_new())
{
//    BN_init(d_bn);
    copy(d_bn, *other.d_bn);
}
