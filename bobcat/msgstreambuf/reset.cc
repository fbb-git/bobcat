#include "msgstreambuf.ih"

void MsgStreambuf::reset(std::ostream *ostr)
{
    if (ostr == 0)
        throw Errno(1, "Can't reset a MsgStreambuf to a 0-ptr");

    d_ostr->flush();

    d_ostr = ostr;
    d_newMsg = true;
}
