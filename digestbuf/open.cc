#include "digestbuf.ih"

void DigestBuf::open()
{
    EVP_DigestInit_ex(&d_pimpl->ctx, d_pimpl->md, 0);
    setp(d_pimpl->buffer, d_pimpl->buffer + d_pimpl->bufsize); 
}
