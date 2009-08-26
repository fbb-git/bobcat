#include "bigint.ih"

BigInt &BigInt::setBigEndian(std::string const &bytes, bool negative)
{
    BN_bin2bn(reinterpret_cast<unsigned char const *>(bytes.data()), 
                bytes.length(), &d_bn);
    setNegative(negative);
    return *this;
}
