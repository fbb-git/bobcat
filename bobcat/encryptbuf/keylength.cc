#include "encryptbuf.ih"

size_t EncryptBuf::keyLength() const
{
    return EVP_CIPHER_CTX_key_length(d_pimpl->ctx);
}
