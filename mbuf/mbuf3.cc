#include "mbuf.hh"

Mbuf::Mbuf(string const &name, size_t maxCount, string const &tag, 
                            bool throwing)
:
    d_ofstr(new ofstream(name)),
    d_ostr(d_ofstr->rdbuf()),

    d_firstChar(true),
    d_throw(throwing),

    d_count(0),
    d_maxCount(maxCount),
    d_lineExcess(maxCount == 0),

    d_showLineNr(false),
    d_lineNr(0),
    d_lineTag("Line")
{
    setTag(tag);
    inspectOfstr(name);
}

// If a MsgStream is created by name and a second MsgStream is intialized
// using the initial stream's MsgBuf then the initial MsgStream should outlive
// the second MsgStream. If not then the 2nd MsgStream's MsgBuf::d_ostr will
// no longer refer to a valid streambuf.
