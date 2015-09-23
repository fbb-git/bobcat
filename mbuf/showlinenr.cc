#include "mbuf.hh"

inline void Mbuf::setLineNr(size_t lineNr)
{
    d_showLineNr = true;
    d_lineNr = lineNr;
}

