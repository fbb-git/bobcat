#include "decryptbuf.ih"

int DecryptBuf::overflow(int c)
{
    update();
    open();

    if (c != EOF)
    {
        *pptr() = static_cast<char>(c);         
        pbump(1);
    }
    return c;
}
