#include "mstream.ih"

namespace FBB
{

std::ostream &flush(std::ostream &os)
{
    os.flush();

    if (Mstream *mp = dynamic_cast<Mstream *>(&os))
    {
        if (mp->throws())
            throw Errno(mp->id());

        if (mp->lineExcess())
            throw Errno(mp->id()) << "Exceeding max. # of " << 
                        mp->maxCount() << " messages";
    }
    return os;
}

} // FBB
