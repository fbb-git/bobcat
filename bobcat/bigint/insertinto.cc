#include "bigint.ih"

ostream &BigInt::insertInto(ostream &out) const
{
    char *cp = 
        (
            out.flags() & ios::dec ?        // No oct conversion
                BN_bn2dec
            :
                BN_bn2hex
        )(&d_bn);

    out << cp;
    OPENSSL_free(cp);

    return out;
}
