#include "encryptbuf.hh"

void EncryptBuf::update()
{
    d_pimpl->active = true;

    int outLen;

    EVP_EncryptUpdate(&d_pimpl->ctx, 
            reinterpret_cast<unsigned char *>(d_pimpl->out), 
            &outLen, 
            reinterpret_cast<unsigned char const *>(d_pimpl->buffer), 
            pptr() - pbase());

    d_pimpl->outStream.write(d_pimpl->out, outLen);

}
