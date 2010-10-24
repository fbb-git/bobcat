#include "mstream.ih"

namespace FBB
{

std::ostream &flushm(std::ostream &os)
{
    os.flush();
    if (Mstream *mp = dynamic_cast<Mstream *>(&os))
    {
        if (mp->throwing())
        {
            if (mp->count() >= mp->maxCount())
                throw Errno(mp->id()) << "Exceeding max. # of " << 
                            mp->maxCount() << " messages";
            else
                throw Errno(mp->id(), "FBB::Mstream");
        }
    }
    return os;
}

} // FBB
