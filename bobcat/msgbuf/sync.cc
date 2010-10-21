#include "msgbuf.ih"

int Msgbuf::sync()
{
    d_ostr->flush();
    d_newMsg = true;

    return 0;
}
