#include "diffiehellman.ih"

string DiffieHellman::key(istream &peerPublicStream)
{
    skip(peerPublicStream, 2);
    
    BIGNUM *otherPubKey;

    if (not read(peerPublicStream, &otherPubKey))
        throw Exception{} << s_header << 
                                "could not read the peer's public key";
        
    BN_free(d_otherPubKey);
    d_otherPubKey = otherPubKey;
    
    return key();
}


