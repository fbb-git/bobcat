#include "mbuf.ih"

void Mbuf::reset(Mbuf const &other)
{
    sync();

    d_ofstr = other.d_ofstr;
    d_ostr.rdbuf(other.d_ostr.rdbuf());

    d_firstChar = true;
    d_throw  = other.d_throw;

    d_tag        = other.d_tag;
    d_count      = other.d_count;
    d_maxCount   = other.d_maxCount;
    d_lineExcess = other.d_lineExcess;

    d_showLineNrs = other.d_showLineNrs;
    d_lineNr      = other.d_lineNr;
    d_lineTag     = other.d_lineTag;
}
