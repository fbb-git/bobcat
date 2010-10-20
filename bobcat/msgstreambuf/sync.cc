#include "msgstreambuf.ih"

int MsgStreambuf::sync()
{
    d_ostr->flush();
    d_newMsg = true;

    return 0;
}
