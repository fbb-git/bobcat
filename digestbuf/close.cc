#include "digestbuf.ih"

void DigestBuf::close()
{
    char *digestbuf = new char[EVP_MAX_MD_SIZE];

    if (pptr() > pbase())
       EVP_DigestUpdate(&d_pimpl->ctx, d_pimpl->buffer, pptr() - pbase());

    unsigned int digestbufLen;
         
    EVP_DigestFinal_ex(&d_pimpl->ctx, 
                    reinterpret_cast<unsigned char *>(digestbuf), 
                    &digestbufLen);
    d_pimpl->digest.assign(digestbuf, digestbufLen);
    delete[] digestbuf;

    EVP_MD_CTX_cleanup(&d_pimpl->ctx);
}
