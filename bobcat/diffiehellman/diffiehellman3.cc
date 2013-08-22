#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(istream &initiatorPublicStream)
:
    d_dh(DH_new(), DH_free),
    d_otherPubKey(0, BN_free)
{
    if (not load(initiatorPublicStream))
        throw Exception() << s_header << "could not load public values";

    checkDHparameters();

    d_otherPubKey.reset(d_dh->pub_key);
    d_dh->pub_key = 0;
}










