#include "diffiehellman.ih"

bool DiffieHellman::read(istream &in, BIGNUM **dest)
{
    uint32_t length;

    in.read(reinterpret_cast<char *>(&length), sizeof(uint32_t));
    length = ntohl(length);

    char buffer[length];
    in.read(buffer, length);

    BN_free(*dest);

    *dest = BN_bin2bn(
                reinterpret_cast<unsigned char const *>(buffer), length, 0
            );

    return *dest;
}



