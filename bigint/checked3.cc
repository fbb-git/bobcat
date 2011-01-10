#include "bigint.ih"

void BigInt::checked3(BIGNUM *div, BIGNUM *rem, 
                      BigInt const &rhs, char const *op) const
{
    BNCTX ctx;
  
    if (BN_div(div, rem, &d_bn, &rhs.d_bn, ctx) != 1)
        throw Errno("BigInt ") << op << " failed";
}
