#include "diffiehellman.ih"

    // check the DH parameters. If all's well return, otherwise
    // write messages or throw an exception
    // 
void DiffieHellman::checkDHparameters()
{
    int result;
    int ret;

    ret = DH_check(d_dh, &result);      // 0: check fails, 1: check OK

    BIGNUM const *g;
    BIGNUM const *prime;
    DH_get0_pqg(d_dh, &prime, 0, &g);

    d_prime = BigInt{*prime};

    if (ret == 1)
        return;

    if (result & (DH_CHECK_P_NOT_PRIME | DH_CHECK_P_NOT_SAFE_PRIME))
        throw Exception{} << s_header << "invalid prime generated"; 


    BigInt generator(g);

    if (result & DH_NOT_SUITABLE_GENERATOR)
        wmsg << s_header << generator << " is not a generator for the "
            "computed prime" << endl;

    else if (result & DH_UNABLE_TO_CHECK_GENERATOR)
        wmsg << s_header << "cannot check the validity of generator " << 
            generator << endl;

    else 
        throw Exception{} << s_header << "parameter check fails"; 
}


