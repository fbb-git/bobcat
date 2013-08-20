#include "diffiehellman.ih"

string DiffieHellman::key() const
{
    size_t length = DH_size(d_dh.get());

    char buffer[length];

    if 
    (
        DH_compute_key(reinterpret_cast<unsigned char *>(buffer), 
                       d_dh->pub_key, d_dh.get()) 
        == -1
    )
        throw Exception() << s_header << "could not compute the shared key";

    string ret(buffer, buffer + length);

    return ret;
}
