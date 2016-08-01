#include "diffiehellman.ih"

    // given the current user's (initiator or peer) private key and the 
    // other party's public key, compute the shared secret 
string DiffieHellman::key() const
{
    size_t length = DH_size(d_dh);

    char buffer[length];


    if 
    (
        DH_compute_key(reinterpret_cast<unsigned char *>(buffer), 
                       d_otherPubKey, d_dh) 
        == -1
    )
        throw Exception{} << s_header << "could not compute the shared key";


    string ret(buffer, buffer + length);

    BigInt theKey(ret);

    BigInt qValue{(d_prime - 1) >> 1};
                                // (prime - 1) / 2 is also prime, as
                                // prima is a safe prime. qValue, according to
                                // RFC 2631 should be so that p = j * q + 1
                                // is prime. Here j == 2
    if 
    (
        theKey == 1 || theKey >= d_prime - 1 || 
        theKey.expModc(qValue, d_prime) != 1
    )
        throw Exception{} << "Key not resistant to the small group attack";

    return ret;
}


