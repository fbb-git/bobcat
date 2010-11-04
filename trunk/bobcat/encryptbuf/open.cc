#include "encryptbuf.ih"

void EncryptBuf::open()
{
    setp(d_pimpl->buffer, d_pimpl->buffer + d_pimpl->bufsize); 
}
