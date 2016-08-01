#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(istream &publicStream, istream &privateStream)
:
    DiffieHellman(publicStream)
{
    BIGNUM *priv = 0;
    
    if (not read(privateStream, &priv))
        throw Exception{} << s_header << "could not load private key";

    DH_set0_key(d_dh, 0, priv);         // DH_set0_key owns the received key
}










