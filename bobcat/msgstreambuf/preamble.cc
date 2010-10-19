#include "msgstreambuf.ih"

void MsgStreambuf::preamble()
{
    if (not d_ostr->good())
        return;

    if (d_newMsg)
    {
        d_newMsg = false;

        if (d_tag.length())
        {
            *d_ostr << d_tag;                   // starts with [

            if (d_maxCount != UINT_MAX)
                *d_ostr << ' ' << ++d_count;

            *d_ostr << "] ";
            if (d_count > d_maxCount)
                throw Errno(1) << "Exceeded " << d_maxCount << ' ' << 
                                  d_tag << " messages";
        }

        if (d_showLineNrs)
            *d_ostr << "Line " << d_count << ": ";
    }
}
