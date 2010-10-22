#include "msgstream.ih"

void MsgStream::reset()
{
    clear();                // clear the current stream
    d_ofstream.clear();     // clear the f-stream part
    Msgbuf::reset();        // reset the inherited part
}
