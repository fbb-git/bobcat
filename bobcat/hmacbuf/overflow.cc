#include "hmacbuf.ih"

int HMacBuf::overflow(int c)
{
    HMAC_Update(&d_pimpl->ctx, 
                    reinterpret_cast<unsigned char *>(d_pimpl->buffer), d_pimpl->bufsize);
    setp(d_pimpl->buffer, d_pimpl->buffer + d_pimpl->bufsize);

    if (c != EOF)
    {
        *pptr() = static_cast<char>(c);         
        pbump(1);
    }
    return c;
}
