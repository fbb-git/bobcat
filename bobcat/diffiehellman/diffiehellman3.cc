#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(istream &initiatorPublicStream)
:
    d_dh(0, DH_free)
{
    if (not load(in))
        throw Exception() << s_header << "could not load public values";

    checkDHparameters();
}










