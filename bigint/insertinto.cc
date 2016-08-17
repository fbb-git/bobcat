#include "bigint.ih"

#include <iostream>

ostream &BigInt::insertInto(ostream &out) const
{
    int flags = out.flags();

    char *cp =                              // call function to use
        (
            flags & ios::hex ? BN_bn2hex :
            flags & ios::oct ? bn2oct    :
                               BN_bn2dec
        )(d_bn);

    bool isNegative = (*cp == '-');
    
    char *skipZeroes = cp + isNegative;

    while (*skipZeroes == '0')              // cut off leading zeros
        ++skipZeroes;

    if ((flags & ios::oct) || *skipZeroes == 0) // if just 1 char or oct: 
        --skipZeroes;                           // keep 1 '0'

    if (isNegative)
        *--skipZeroes = '-';                // restore the '-'

    out << skipZeroes;                      // insert the value

    if (flags & ios::oct)
        delete[] cp;
    else
        OPENSSL_free(cp);

    return out;
}
