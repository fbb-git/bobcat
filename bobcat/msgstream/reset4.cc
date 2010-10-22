#include "msgstream.ih"

void MsgStream::reset(MsgStream const &msgStream)
{
    clear();                // clear the current stream
    d_ofstream.clear();     // clear the f-stream part

    reset();
    delete d_msgBuf;
    d_msgBuf = new Msgbuf(msgStream.ostr(), msgStream.maxCount(), 
                            msgStream.tag(), msgStream.throwing());
    rdbuf(d_msgBuf);
}
