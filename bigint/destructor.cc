#include "bigint.ih"

BigInt::~BigInt()
{
    BN_free(d_bn);
}
