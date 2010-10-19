#include "msgstreambuf.ih"

// manipulators except endl and ends are not supposed to insert information
// into the stream. So if only if the manipulator is endl or ends preamble
// will be called, prefixing the message with message label and message
// number, if applicable

MsgStream &FBB::operator<<(MsgStream &msgStream, 
                                    std::ostream &(*manip)(std::ostream &))
{
    bool endlManip = 
            manip == static_cast<std::ostream &(*)(std::ostream &)>(endl);
    if 
    (
        (manip == static_cast<std::ostream &(*)(std::ostream &)>(ends))
        ||
        endlManip
    )
        msgStream.d_msgStreambuf.preamble();

    msgStream.d_os << manip;

    if 
    (
        msgStream.partialMsg()
        &&
        (manip == static_cast<std::ostream &(*)(std::ostream &)>(flush))
    )
        msgStream.msgContinues();

    if (endlManip && msgStream.d_msgStreambuf.throwing())
    {
        if (!msgStream.d_os.good())
        {
            msgStream.d_os.clear();
            throw Errno(msgStream.asInt(), "MsgStream");
        }
    }

    return msgStream;
}


