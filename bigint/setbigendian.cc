#include "bigint.ih"

BigInt BigInt::setBigEndian(std::string const &bytes)
{
    BigInt tmp;
    BN_bin2bn(reinterpret_cast<unsigned char const *>(bytes.data()), 
                bytes.length(), &tmp.d_bn);
    return tmp;
}
