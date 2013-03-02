#include "encryptbuf.ih"

EVP_CIPHER_CTX *EncryptBuf::cipherCtx()
{
    return &d_pimpl->ctx;
}
