#include "bigint.hh"

BigInt BigInt::rand(size_t size, Msb msb, Lsb lsb)
{
    BigInt ret;
    if (BN_rand(&ret.d_bn, size, msb, lsb) != 1)
        throw Exception() << "BigInt::rand() failed";
    return ret;
}
