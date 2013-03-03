#include "bigint.ih"

BigInt BigInt::prime(size_t nBits, BigInt const *mod, BigInt const *rem,
                     PrimeType primeType)
{
    BigInt ret;
    bool useArgs = mod != 0 && rem != 0;
    if 
    (
        BN_generate_prime(&ret.d_bn, nBits, primeType, 
            useArgs ? &(mod->d_bn) : 0, 
            useArgs ? &(rem->d_bn) : 0,
            0, 0)
        == 0
    )
        throw Exception() << "BigInt::prime() failed";

    return ret;
}
