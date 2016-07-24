#include "encryptbuf.ih"

EncryptBufImp::~EncryptBufImp()
{
    EVP_CIPHER_CTX_free(ctx);
    delete [] buffer;
    delete [] out;
}
