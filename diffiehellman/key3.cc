#include "diffiehellman.hh"

string DiffieHellman::key(istream &peerPublicStream)
{
    skip(peerPublicStream, 2);
    
    BIGNUM *otherPubKey;
    if (not read(peerPublicStream, &otherPubKey))
        throw Exception() << s_header << 
                                "could not read the peer's public key";
        
    d_otherPubKey.reset(otherPubKey);
    
    return key();
}


