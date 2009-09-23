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

    bool isNegative = (*cp == '-');
    
    char *skipZeroes = cp + isNegative;

    while (*skipZeroes == '0')              // cut off leading zeros
        ++skipZeroes;

    if (cp + isNegative + 1 == skipZeroes)  // if just 1 char: keep it.
        --skipZeroes;

    if (isNegative)
        *--skipZeroes = '-';                // restore the '-'

    out << skipZeroes;                      // insert the value

    OPENSSL_free(cp);

    return out;
}
