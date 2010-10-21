#include "msgbuf.ih"

void Msgbuf::showTag()
{
    if (d_tag.empty())
        return;

    *d_ostr << d_tag;                   // starts with [

    if (d_maxCount != UINT_MAX)
        *d_ostr << ' ' << ++d_count;

    *d_ostr << "] ";
    if (d_count > d_maxCount)
        throw Errno(1) << "Exceeded " << d_maxCount << ' ' << 
                          d_tag << " messages";
}
