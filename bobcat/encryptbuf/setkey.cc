#include "encryptbuf.ih"

void EncryptBuf::setKey(string key, size_t numberOfBits)
{
    if (d_pimpl->active)
        throw Errno(1, "Can't change Key during encryption");

    if (numberOfBits == 0)
        numberOfBits = 8 * key.length();

    key.resize(EVP_MAX_KEY_LENGTH);

    if 
    (
        !EVP_EncryptInit_ex(&d_pimpl->ctx, 0, 0,
            reinterpret_cast<unsigned char const *>(key.c_str()), 0)
    )
        throw Errno(1, "Couldn't set Key");

    
    EVP_CIPHER_CTX_set_key_length(&d_pimpl->ctx, numberOfBits);
}
