#include "mbuf.ih"

void Mbuf::setLineNr(size_t lineNr)
{
    d_lineNr = lineNr;
    d_showLineNr = true;
}

