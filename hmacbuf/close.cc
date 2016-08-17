#include "hmacbuf.ih"

void HMacBuf::close()
{
    char *digestbuf = new char[EVP_MAX_MD_SIZE];

    if (pptr() > pbase())
       HMAC_Update(d_pimpl->ctx, 
                   reinterpret_cast<unsigned char *>(d_pimpl->buffer), 
                   pptr() - pbase());
         
    unsigned int digestbufLen;
    HMAC_Final(d_pimpl->ctx, reinterpret_cast<unsigned char *>(digestbuf), 
               &digestbufLen);

    d_pimpl->digest.assign(digestbuf, digestbufLen);
    HMAC_CTX_free(d_pimpl->ctx);

    delete[] digestbuf;
}
