#include "bigint.ih"

BigInt const BigInt::rand(size_t size, Msb msb, Lsb lsb)
{
    BigInt ret;
    if (BN_rand(&ret.d_bn, size, msb, lsb) != 1)
        throw Errno("BigInt::rand() failed");
    return ret;
}
