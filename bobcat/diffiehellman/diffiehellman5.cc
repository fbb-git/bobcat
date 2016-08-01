#include "diffiehellman.ih"

DiffieHellman::DiffieHellman(istream &publicStream, istream &privateStream)
:
    DiffieHellman(publicStream)
{
    BIGNUM *priv = BN_new();

    if (not (priv && read(privateStream, &priv)))
    {
        BN_free(priv);
        throw Exception() << s_header << "could not load private key";
    }

    DH_set0_key(d_dh, d_otherPubKey, priv); // DH_set0_key owns 
                                            // the received key
    d_otherPubKey = 0;
    
}










