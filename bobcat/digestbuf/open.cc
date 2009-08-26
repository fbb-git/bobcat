#include "digestbuf.ih"

void DigestBuf::open()
{
    EVP_DigestInit(&d_pimpl->ctx, d_pimpl->md);
    setp(d_pimpl->buffer, d_pimpl->buffer + d_pimpl->bufsize); 
}
