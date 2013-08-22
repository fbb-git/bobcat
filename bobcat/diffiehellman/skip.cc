#include "diffiehellman.ih"

void DiffieHellman::skip(istream &in, size_t count)
{
    for (; count--; )
    {
        uint32_t length;

        in.read(reinterpret_cast<char *>(&length), sizeof(uint32_t));
        length = ntohl(length);

        in.seekg(length, ios::cur);
    }
}



