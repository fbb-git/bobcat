#include "diffiehellman.ih"

DiffieHellman::~DiffieHellman()
{
    DH_free(d_dh);
    BN_free(d_otherPubKey);
}
