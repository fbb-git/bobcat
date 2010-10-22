#include "msgstream.ih"

namespace FBB
{

std::ostream &flushm(std::ostream &os)
{
    os.flush();
    if (MsgStream *mp = dynamic_cast<MsgStream *>(&os))
    {
        mp->reset();
        if (mp->throwing())
            throw Errno(mp->id(), "FBB::MsgStream");
    }
    return os;
}

} // FBB
