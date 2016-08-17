#include "encryptbuf.ih"

EncryptBuf::~EncryptBuf()
{
    update();

    int outLen;

    EVP_EncryptFinal_ex(d_pimpl->ctx, 
            reinterpret_cast<unsigned char *>(d_pimpl->out), &outLen);
    d_pimpl->outStream.write(d_pimpl->out, outLen);

    delete d_pimpl;
}
