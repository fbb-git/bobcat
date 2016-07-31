#include "bigint.ih"

BigInt::BigInt(char const *bigEndian, size_t length, bool negative)
:
    d_bn(BN_new())
{
    BN_bin2bn(reinterpret_cast<unsigned char const *>(bigEndian), length,
                d_bn);

    setNegative(negative);
}
