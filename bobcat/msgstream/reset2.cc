#include "msgstream.ih"

void MsgStream::reset(std::ostream &ostr, size_t maxCount,
                     std::string const &tag, bool throwing)
{
    clear();                // clear the current stream
    d_ofstream.clear();     // clear the f-stream part

    reset();
    delete d_msgBuf;
    d_msgBuf = new Msgbuf(ostr, maxCount, tag, throwing);
    rdbuf(d_msgBuf);
}
