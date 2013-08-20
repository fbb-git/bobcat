#include "diffiehellman.ih"

size_t DiffieHellman::check(BigInt const &primeParam, 
                            BigInt const &generatorParam)
{
    DH *dh = newDH();

    BigInt prime(primeParam);
    BigInt generator(generatorParam);

    dh->p = const_cast<BIGNUM *>(&prime.bignum());
    dh->g = const_cast<BIGNUM *>(&generator.bignum());

    int ret;

    if (DH_check(dh, &ret) == 0) 
        ret = CHECK_FAILS;

    DH_free(dh);

    return ret;
}








