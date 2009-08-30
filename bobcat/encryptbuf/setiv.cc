#include "encryptbuf.ih"

void EncryptBuf::setIv(string const &iv)
{
    if (d_pimpl->active)
        throw Errno(1, "Can't change IV during encryption");

    if 
    (
        !EVP_EncryptInit_ex(&d_pimpl->ctx, 0, 0, 0,
            reinterpret_cast<unsigned char const *>(iv.c_str()))
    )
        throw Errno(1, "Couldn't set IV");
}
