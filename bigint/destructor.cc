#include "bigint.hh"

BigInt::~BigInt()
{
    BN_free(&d_bn);
}
