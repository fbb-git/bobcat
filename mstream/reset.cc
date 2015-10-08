#include "mstream.ih"

void Mstream::reset(Mstream const &mstr)
{
    if (Mbuf *mb = dynamic_cast<Mbuf *>(mstr.rdbuf()))
        Mbuf::reset(*mb);
    else
        throw Exception(1) << "Can't reset Mstream without Mbuf";
}
