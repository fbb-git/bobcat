#include "msgstream.ih"

MsgStream::~MsgStream()
{
    reset();
    rdbuf(0);
    delete d_msgBuf;
}
