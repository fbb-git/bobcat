#include "diffiehellman.ih"

size_t DiffieHellman::check(BigInt const &primeParam, 
                            BigInt const &generatorParam)
{
    struct dh_st dhStruct;

    BigInt prime(primeParam);
    BigInt generator(generatorParam);

    dhStruct.p = const_cast<BIGNUM *>(&prime.bignum());
    dhStruct.g = const_cast<BIGNUM *>(&generator.bignum());

    int ret;

    return DH_check(&dhStruct, &ret) ? ret : CHECK_FAILS;
}








