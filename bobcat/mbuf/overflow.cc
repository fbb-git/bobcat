#include "mbuf.ih"

int Mbuf::overflow(int c)
{
    atNewline();
    d_ostr.put(c);
    return c;
}

