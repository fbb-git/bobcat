#include "mstream.ih"

namespace FBB
{

std::ostream &flushm(std::ostream &os)
{
    os.flush();
    if (Mstream *mp = dynamic_cast<Mstream *>(&os))
    {
        if (mp->throwing())
            throw Errno(mp->id(), "FBB::Mstream");
    }
    return os;
}

} // FBB
