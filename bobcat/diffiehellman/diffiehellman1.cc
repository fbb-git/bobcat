#include "diffiehellman.hh"

DiffieHellman::DiffieHellman(size_t primeLength, size_t generator, 
                             bool progress)
:
    d_dh(
        DH_generate_parameters(
            primeLength, generator, 
            progress? callback : 0, 0
        ), DH_free
    ),
    d_otherPubKey(0, DH_free)
{
    if (progress)
        cout << endl;

    if (d_dh == 0)
        throw Exception() << s_header << "generating parameters failed";

    checkDHparameters();
}










