#include "msgstreambuf.ih"

int MsgStreambuf::overflow(int c)
{
    d_ostr->put(c);
    return c;
}

