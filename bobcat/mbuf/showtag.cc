#include "mbuf.ih"

void Mbuf::showTag()
{
    if (d_tag.empty())
        return;

    d_ostr << d_tag;                    // starts with [

    if (d_showLineNrs)
    {
        d_ostr << ' ' << ++d_count;
        d_lineExcess = d_count >= d_maxCount;
    }

    d_ostr << "] ";
}
