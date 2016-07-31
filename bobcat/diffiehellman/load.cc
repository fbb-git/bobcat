#include "diffiehellman.ih"

bool DiffieHellman::load(istream &publicData, BIGNUM **pub_key)
{
    BIGNUM *p = BN_new();
    BIGNUM *g = BN_new();
    *pub_key = BN_new();

    return 
        read(publicData, &p) && 
        read(publicData, &g) &&   
        read(publicData, pub_key) &&
        DH_set0_pqg(d_dh, p, 0, g);
}
