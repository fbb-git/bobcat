#include "bigint.ih"

BigInt::~BigInt()
{
    BN_clear(&d_bn);
}
