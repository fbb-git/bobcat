#include "bigint.ih"

// toggles all bits and sign


BigInt const BigInt::tilde() const
{
    BigInt tmp(*this);

    size_t nBytes = sizeInBytes();
    unsigned char buf[nBytes];

    BN_bn2bin(&tmp.d_bn, buf);

    for (size_t idx = nBytes; idx--; )
        buf[idx] = ~buf[idx];

    BN_bin2bn(buf, nBytes, &tmp.d_bn);
    tmp.setNegative(!isNegative());

    return tmp;
}

