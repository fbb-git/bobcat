<<<<<<< HEAD
#include "mstream.ih"
=======
#include "mstream.hh"
>>>>>>> upstream/4.01.00

namespace FBB
{

std::ostream &noid(std::ostream &os)
{
    os.flush();

    if (Mstream *mp = dynamic_cast<Mstream *>(&os))
    {
        if (mp->throws())
            throw Exception();

        if (mp->lineExcess())
            throw Exception() << "Exceeding max. # of " << mp->maxCount() << 
                                                                " messages";
    }
    return os;
}

} // FBB
