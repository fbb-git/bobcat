#include "hmacbuf.ih"

void HMacBuf::open()
{
    d_pimpl->ctx = HMAC_CTX_new();

    HMAC_CTX_reset(d_pimpl->ctx);
    HMAC_Init_ex(d_pimpl->ctx, d_pimpl->key.c_str(), d_pimpl->key.length(), 
              d_pimpl->md, 0);

    setp(d_pimpl->buffer, d_pimpl->buffer + d_pimpl->bufsize); 
}
