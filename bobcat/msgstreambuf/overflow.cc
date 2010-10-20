#include "msgstreambuf.ih"

int MsgStreambuf::overflow(int c)
{
    atNewline();
    d_ostr->put(c);
    return c;
}

