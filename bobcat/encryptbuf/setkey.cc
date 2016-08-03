#include "encryptbuf.ih"

void EncryptBuf::setKey(string key, size_t numberOfBytes)
{
    if (d_pimpl->active)
        throw Exception{1} << "Can't change Key during encryption";

    if (numberOfBytes == 0)
        numberOfBytes = key.length();

    key.resize(EVP_MAX_KEY_LENGTH);

    installKey(key, numberOfBytes);
}
