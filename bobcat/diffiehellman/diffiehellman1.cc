#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(size_t primeLength, size_t generator)
:
    d_dh(DH_generate_parameters(primeLength, generator, 0, 0), DH_free)
{
    if (dh == 0)
        throw Exception() << s_header << "generating parameters failed";

    checkDHparameters();
}










