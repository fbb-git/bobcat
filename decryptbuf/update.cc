#include "decryptbuf.ih"

#include <openssl/err.h>
#include <bobcat/ohexstreambuf>
#include <iostream>

void DecryptBuf::update()
{
    d_pimpl->active = true;

    int outLen;

//    {
//        OHexStreambuf ohex(cerr, 16);
//        ostream out(&ohex);
//        out.write(d_pimpl->buffer, pptr() - pbase());
//        cerr << '\n';
//    }

    if (EVP_DecryptUpdate(d_pimpl->ctx, 
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




