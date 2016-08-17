#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(istream &initiatorPublicStream)
:
    d_dh(DH_new())
{
    if (not (initiatorPublicStream 
             and load(initiatorPublicStream, &d_otherPubKey))
    )
        throw Exception{} << s_header << "could not load public values";

    checkDHparameters();
}










