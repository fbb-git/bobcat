#include "diffiehellman.ih"

string DiffieHellman::key() const
{
    size_t length = DH_size(d_dh.get());

    char buffer[length];

    if 
    (
        DH_compute_key(reinterpret_cast<unsigned char *>(buffer), 
                       d_otherPubKey.get(), d_dh.get()) 
        == -1
    )
        throw Exception() << s_header << "could not compute the shared key";

    
    string ret(buffer, buffer + length);

    BigInt theKey(ret);
    BigInt prime(const_cast<BIGNUM const *>(d_dh->p));
    BigInt qValue((prime - 1) >> 1);
                                // (prime - 1) / 2 is also prime, as
                                // prima is a safe prime. qValue, according to
                                // RFC 2631 should be so that p = j * q + 1
                                // is prime. Here j == 2

    if 
    (
        theKey == 1 || theKey >= prime - 1 || 
        theKey.expModc(qValue, prime) != 1
    )
        throw Exception() << "Key not resistant to the small group attack";

    return ret;
}
