#include "bigint.ih"

char *BigInt::bigEndian() const
{
    char *ret = new char[sizeInBytes()];
    
    BN_bn2bin(d_bn, reinterpret_cast<unsigned char *>(ret));

    return ret;    
}
