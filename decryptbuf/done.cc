#include "decryptbuf.ih"

void DecryptBuf::done()
{
    update();

    int outLen;

    if 
    (
        !EVP_DecryptFinal_ex(d_pimpl->ctx, 
                            reinterpret_cast<unsigned char *>(d_pimpl->out), 
                            &outLen)
    )
        throw Exception{} << "Padding incorrect";

    d_pimpl->outStream.write(d_pimpl->out, outLen);
    d_pimpl->active = false;
}
