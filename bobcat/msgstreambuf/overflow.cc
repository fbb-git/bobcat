#include "msgstreambuf.ih"

int MsgStreambuf::overflow(int c)
{
    atNewLine();
    d_ostr->put(c);
    return c;
}

