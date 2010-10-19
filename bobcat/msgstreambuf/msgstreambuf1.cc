#include "msgstreambuf.ih"

MsgStreambuf::MsgStreambuf(ostream *ostr, size_t maxCount, string const &tag, 
                            bool throwing)
:
    d_ostr(ostr),
    d_throwing(throwing),
    d_lineNr(0),
    d_showLineNrs(false),
    d_count(0),
    d_maxCount(maxCount),
    d_newMsg(true)
{
    if (ostr == 0)
        throw Errno(1, "Can't construct a MsgStreambuf from a 0-ptr");

    setTag(tag);
}
