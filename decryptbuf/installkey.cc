#include "decryptbuf.hh"

void DecryptBuf::installKey(string const &key, size_t numberOfBytes)
{
    EVP_CIPHER_CTX_set_key_length(&d_pimpl->ctx, numberOfBytes);

    if 
    (
        !EVP_EncryptInit_ex(&d_pimpl->ctx, 0, 0,
            reinterpret_cast<unsigned char const *>(key.data()), 0)
    )
        throw Exception(1) << "Couldn't set Key";
}
