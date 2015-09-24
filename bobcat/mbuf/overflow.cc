#include "mbuf.ih"

int Mbuf::overflow(int c)
{
    atFirstChar();
    d_ostr.put(c);
    return c;
}

