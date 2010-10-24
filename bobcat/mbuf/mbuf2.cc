#include "mbuf.ih"

Mbuf::Mbuf(streambuf *buf, size_t maxCount, string const &tag, 
                            bool throwing)
:
    d_ostr(buf),

    d_firstChar(true),
    d_throw(throwing),

    d_count(0),
    d_maxCount(maxCount),
    d_lineExcess(maxCount == 0),

    d_showLineNrs(false),
    d_lineNr(0),
    d_lineTag("Line")
{
    setTag(tag);
}
