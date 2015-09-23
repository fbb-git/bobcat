#include "decryptbuf.hh"

EVP_CIPHER_CTX *DecryptBuf::cipherCtx()
{
    return &d_pimpl->ctx;
}
