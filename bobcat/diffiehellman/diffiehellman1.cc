#include "diffiehellman.ih"

namespace
{
    char const *header = "DiffieHellman: ";
}

DiffieHellman::DiffieHellman(size_t primeLength, size_t generator)
:
    d_dh(0, DH_free)        // initialize the deleter for d_dh
{
    d_dh.reset(
        DH_generate_parameters(primeLength, generator, 0, 0)
    );

    size_t result = check(
                        BigInt(const_cast<BIGNUM const *>(d_dh->p)), 
                        BigInt(const_cast<BIGNUM const *>(d_dh->g))
                    );

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
}






