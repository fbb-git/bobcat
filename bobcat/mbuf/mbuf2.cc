#include "mbuf.ih"

Mbuf::Mbuf(streambuf *buf, size_t maxCount, string const &tag, 
                            bool throwing)
:
    d_ostr(buf),
    d_newMsg(true),
    d_showLineNrs(false),
    d_throw(throwing),
    d_count(0),
    d_lineNr(0),
    d_maxCount(maxCount),
    d_lineExcess(maxCount == 0)
{
    setTag(tag);
}
