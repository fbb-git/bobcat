#include "bigint.ih"

BigInt &BigInt::inverseMod(BigInt const &mod)
{
    mod_inverse(this, mod);
    return *this;
}
