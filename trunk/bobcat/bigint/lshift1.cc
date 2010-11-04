#include "bigint.ih"

BigInt &BigInt::lshift()
{
    if (!BN_lshift1(&d_bn, &d_bn))
        throw Errno("BigInt::lshift() failed");

    return *this;
}


