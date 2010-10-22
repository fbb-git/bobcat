#include "msgbuf.ih"

void Msgbuf::reset()
{
    d_ostr->clear();
    d_newMsg = true;
}
