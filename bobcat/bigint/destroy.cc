#include "bigint.ih"

void BigInt::destroy()
{
    BN_clear(&d_bn);
}
