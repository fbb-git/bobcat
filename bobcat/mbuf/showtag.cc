#include "mbuf.ih"

void Mbuf::showTag()
{
    if (d_tag.empty())
        return;

    d_ostr << d_tag;                    // starts with [

    if (d_maxCount != UINT_MAX)
        d_ostr << ' ' << ++d_count;

    d_ostr << "] ";
}
