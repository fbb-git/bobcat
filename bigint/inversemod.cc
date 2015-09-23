#include "bigint.hh"

BigInt &BigInt::inverseMod(BigInt const &mod)
{
    mod_inverse(this, mod);
    return *this;
}
