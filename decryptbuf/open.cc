#include "decryptbuf.ih"

void DecryptBuf::open()
{
    setp(d_pimpl->buffer, d_pimpl->buffer + d_pimpl->bufsize); 
}
