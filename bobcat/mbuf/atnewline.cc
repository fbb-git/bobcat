#include "mbuf.ih"

void Mbuf::atNewline()
{
    if (not d_newMsg)
        return;

    if (d_lineExcess)
    {
        d_ostr.setstate(ios::badbit);
        return;
    }

    d_newMsg = false;

    if (d_tag.length())
        showTag();

    if (d_showLineNrs)
        d_ostr << "Line " << d_count << ": ";
}
