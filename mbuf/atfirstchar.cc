#include "mbuf.ih"

void Mbuf::atFirstChar()
{
    if (not d_firstChar)
        return;

    d_firstChar = false;

    ++d_count;
    d_lineExcess = d_count + 1 > d_maxCount;    // if d_maxCount == UINT_MAX
                                                // then this is never true

    if (d_lineExcess)
    {
        d_ostr.setstate(ios::badbit);
        return;
    }

    if (d_tag.length())
        showTag();

    if (d_showLineNr)
    {
        d_showLineNr = false;
        d_ostr << d_lineTag << ' ' << d_lineNr << ": ";
    }
}
