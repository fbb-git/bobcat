#include "msgbuf.ih"

int Msgbuf::overflow(int c)
{
    atNewline();
    d_ostr->put(c);
    return c;
}

