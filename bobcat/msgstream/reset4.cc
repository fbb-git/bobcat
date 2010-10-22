#include "msgstream.ih"

void MsgStream::reset(MsgStream const &msgStream)
{
    reset();
    d_ofstream.close();

    delete d_msgBuf;
    d_msgBuf = new Msgbuf(msgStream.ostr(), msgStream.maxCount(), 
                            msgStream.tag(), msgStream.throwing());
    rdbuf(d_msgBuf);
}
