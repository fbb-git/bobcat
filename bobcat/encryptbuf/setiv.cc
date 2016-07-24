#include "encryptbuf.ih"

void EncryptBuf::setIv(string iv)
{
    if (d_pimpl->active)
        throw Exception(1) << "Can't change IV during encryption";

    d_pimpl->iv = iv;

    iv.resize(EVP_MAX_IV_LENGTH);
    if 
    (
        !EVP_EncryptInit_ex(d_pimpl->ctx, 0, 0, 0,
            reinterpret_cast<unsigned char const *>(iv.data()))
    )
        throw Exception(1) << "Couldn't set IV";
}
