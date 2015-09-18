#include "encryptbuf.hh"

int EncryptBuf::overflow(int c)
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
