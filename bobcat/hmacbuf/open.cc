#include "hmacbuf.ih"

void HMacBuf::open()
{
    d_pimpl->ctx = HMAC_CTX();

    HMAC_Init(&d_pimpl->ctx, d_pimpl->key.c_str(), d_pimpl->key.length(), 
              d_pimpl->md);

    setp(d_pimpl->buffer, d_pimpl->buffer + d_pimpl->bufsize); 
}
