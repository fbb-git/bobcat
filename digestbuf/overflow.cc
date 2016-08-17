#include "digestbuf.ih"

int DigestBuf::overflow(int c)
{
    EVP_DigestUpdate(d_pimpl->ctx, d_pimpl->buffer, d_pimpl->bufsize);
    setp(d_pimpl->buffer, d_pimpl->buffer + d_pimpl->bufsize);

    if (c != EOF)
    {
        *pptr() = static_cast<char>(c);         
        pbump(1);
    }
    return c;
}
