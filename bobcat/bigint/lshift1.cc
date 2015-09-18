#include "bigint.hh"

BigInt &BigInt::lshift()
{
    if (!BN_lshift1(&d_bn, &d_bn))
        throw Exception() << "BigInt::lshift() failed";

    return *this;
}


