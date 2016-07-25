#include "encryptbuf.ih"

//#include <iostream>
#include <openssl/err.h>

void EncryptBuf::update()
{
    d_pimpl->active = true;

    int outLen;

//    cerr << "Block: ";
//    cerr.write(
//            d_pimpl->buffer, 
//            pptr() - pbase());
//    cerr << '\n';


    if (EVP_EncryptUpdate(d_pimpl->ctx, 
            reinterpret_cast<unsigned char *>(d_pimpl->out), 
            &outLen, 
            reinterpret_cast<unsigned char const *>(d_pimpl->buffer), 
            pptr() - pbase()) != 1)
    {
        ERR_print_errors_fp(stderr);
        throw 1;
    }

    d_pimpl->outStream.write(d_pimpl->out, outLen);

}
