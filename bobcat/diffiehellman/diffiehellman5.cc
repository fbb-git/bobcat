#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(istream &publicStream, istream &privateStream)
:
    DiffieHellman(publicStream)
{
    if (not read(privateStream, &d_dh->priv_key))
        throw Exception() << s_header << "could not load private key";
}










