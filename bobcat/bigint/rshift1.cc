#include "bigint.ih"

BigInt &BigInt::rshift()
{
    if (!BN_rshift1(&d_bn, &d_bn))
        throw Errno("BigInt::rshift() failed");

    return *this;
}


