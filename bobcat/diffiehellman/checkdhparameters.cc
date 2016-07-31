#include "diffiehellman.ih"

    // check the DH parameters. If all's well return, otherwise
    // write messages or throw an exception
    // 
void DiffieHellman::checkDHparameters()
{
    int result;

    if (DH_check(d_dh, &result) == 0)     // 0: check fails, 1: check OK
        result = CHECK_FAILS;

    if (result == 0)
        return;

    if (result & (DH_CHECK_P_NOT_PRIME | DH_CHECK_P_NOT_SAFE_PRIME))
        throw Exception{} << s_header << "invalid prime generated"; 

    BIGNUM const *notUsed;
    BIGNUM const *g;
    DH_get0_pqg(d_dh, &d_prime, &notUsed, &g);

    BigInt generator(g);

    if (result & DH_NOT_SUITABLE_GENERATOR)
        wmsg << s_header << generator << " is not a generator for the "
            "computed prime" << endl;

    else if (result & DH_UNABLE_TO_CHECK_GENERATOR)
        wmsg << s_header << "cannot check the validity of generator " << 
            generator << endl;

    else if (result & CHECK_FAILS)
        throw Exception{} << s_header << "parameter check fails"; 
}
