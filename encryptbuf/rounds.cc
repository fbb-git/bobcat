#include "encryptbuf.hh"

size_t EncryptBuf::rounds() const
{
    size_t nRounds;
    return EVP_CIPHER_CTX_ctrl(&d_pimpl->ctx, EVP_CTRL_GET_RC5_ROUNDS, 0, 
                                                                 &nRounds) ?
                nRounds : 0;
}
