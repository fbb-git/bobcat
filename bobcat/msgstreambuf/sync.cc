#include "msgstreambuf.ih"

int MsgStreambuf::sync()
{
    d_ostr->flush();
    d_newMsg = true;

    d_throw = 1;

    return 0;
}
