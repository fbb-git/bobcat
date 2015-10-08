#include "diffiehellman.ih"

void DiffieHellman::write(ostream &out, BIGNUM const *bn, char *buffer,
                                                        uint32_t nBytes) const
{
    uint32_t nBytesStd = htonl(nBytes);

    out.write(reinterpret_cast<char const *>(&nBytesStd), sizeof(uint32_t));

    BN_bn2bin(bn, reinterpret_cast<unsigned char *>(buffer));

    out.write(buffer, nBytes);
}
