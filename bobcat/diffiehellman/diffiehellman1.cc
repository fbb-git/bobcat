#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(size_t primeLength, size_t generator, 
                             bool progress)
:
    d_dh(DH_new()),
    d_otherPubKey(0)
{
    if (progress)                   // if true, prime generation is shown
        cout << '\n';               // as a series of dots etc, which start
                                    // on a new line

    BN_GENCB *cb = BN_GENCB_new();
    BN_GENCB_set(cb, callback, 0);
    
    if (not DH_generate_parameters_ex(d_dh, primeLength, generator, 
                progress ? cb : 0))
        throw Exception{} << s_header << "generating parameters failed";

    BN_GENCB_free(cb);

    if (progress)
        cout << endl;

    checkDHparameters(generator);
}










