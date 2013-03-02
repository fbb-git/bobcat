#include "decryptbuf.ih"

void DecryptBuf::update()
{
    d_pimpl->active = true;

    int outLen;

    EVP_DecryptUpdate(&d_pimpl->ctx, 
            reinterpret_cast<unsigned char *>(d_pimpl->out), 
            &outLen, 
            reinterpret_cast<unsigned char const *>(d_pimpl->buffer), 
            pptr() - pbase());

    d_pimpl->outStream.write(d_pimpl->out, outLen);

}
