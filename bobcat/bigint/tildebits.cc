#include "bigint.hh"

// toggles all bits and sign


BigInt &BigInt::tildeBits()
{
    size_t nBytes = sizeInBytes();
    unsigned char buf[nBytes];
    bool sign = isNegative();

    BN_bn2bin(&d_bn, buf);

    for (size_t idx = nBytes; idx--; )
        buf[idx] = ~buf[idx];

    BN_bin2bn(buf, nBytes, &d_bn);
    setNegative(!sign);

    return *this;
}

