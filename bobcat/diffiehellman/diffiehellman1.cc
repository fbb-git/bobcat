#include "diffiehellman.ih"

namespace
{
    char const *header = "DiffieHellman: ";
}

DiffieHellman::DiffieHellman(size_t primeLength, size_t generator)
{
    DH *dh = DH_generate_parameters(primeLength, generator, 0, 0);

    if (dh == 0)
        throw Exception() << header << "generating parameters failed" << endl;

    d_prime = BigInt(const_cast<BIGNUM const *>(dh->p));
    d_generator = BigInt(const_cast<BIGNUM const *>(dh->g));

    size_t result = check(d_prime, d_generator);

    DH_free(dh);

    if (result == 0)
        return;

    if (result & (DH_CHECK_P_NOT_PRIME | DH_CHECK_P_NOT_SAFE_PRIME))
        throw Exception() << header << "invalid prime generated" << endl; 

    if (result & DH_NOT_SUITABLE_GENERATOR)
        wmsg << header << generator << " is not a generator for the "
            "computed prime" << endl;

    else if (result & DH_UNABLE_TO_CHECK_GENERATOR)
        wmsg << header << "cannot check the validity of generator " << 
            generator << endl;

    else if (result & CHECK_FAILS)
        throw Exception() << header << "parameter check fails" << endl; 

    d_publicKey = BigInt(const_cast<BIGNUM const *>(dh->pub_key));
}










