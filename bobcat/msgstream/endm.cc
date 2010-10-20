#include "msgstream.ih"

std::ostream &endm(std::ostream &os)
{
    os.put('\n').flush();
    if (MsgStream *mp = dynamic_cast<MsgStream *>(&os))
    {
        if (mp->good() && mp->throwing())
            throw Errno(mp->asInt(), "FBB::MsgStream");
    }
}
