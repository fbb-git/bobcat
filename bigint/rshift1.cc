#include "bigint.ih"

BigInt &BigInt::rshift()
{
    if (!BN_rshift1(d_bn, d_bn))
        throw Exception{} << "BigInt::rshift() failed";

    return *this;
}


