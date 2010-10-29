#include "mbuf.ih"

inline void Mbuf::setLineNr(size_t lineNr)
{
    d_showLineNrs = true;
    d_lineNr = lineNr;
}

