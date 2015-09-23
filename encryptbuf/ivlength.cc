#include "encryptbuf.hh"

size_t EncryptBuf::ivLength() const
{
    return EVP_CIPHER_CTX_iv_length(&d_pimpl->ctx);
}
