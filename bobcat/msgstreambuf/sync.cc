#include "msgstreambuf.ih"

int MsgStreambuf::sync()
{
    d_ostr->flush();
    d_newMsg = true;

    if (d_throwing)
        throw 1;

    return 0;
}
