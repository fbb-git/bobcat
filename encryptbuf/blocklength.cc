#include "encryptbuf.hh"

size_t EncryptBuf::blockLength() const
{
    return EVP_CIPHER_CTX_block_size(&d_pimpl->ctx);
}
