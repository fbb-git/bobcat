#include "mbuf.ih"

void Mbuf::reset(Mbuf const &other)
{
    sync();

    d_ofstr = other.d_ofstr;
    d_ostr.rdbuf(other.d_ostr.rdbuf());

    d_newMsg = true;
    d_showLineNrs = other.d_showLineNrs;
    d_throw = other.d_throw;
    d_count = other.d_count;
    d_lineNr = other.d_lineNr;
    d_maxCount = other.d_maxCount;
    d_tag = other.d_tag;
    d_lineExcess = other.d_lineExcess;
}
