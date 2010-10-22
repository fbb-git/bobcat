#include "msgstream.ih"

MsgStream::MsgStream(std::ostream &ostr, size_t maxCount, 
                             std::string const &tag, bool throwing)
:
    Msgbuf(ostr, maxCount, tag, throwing),
    std::ostream(this),
    d_msgBuf(0)
{}
