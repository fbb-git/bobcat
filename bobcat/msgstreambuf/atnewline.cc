#include "msgstreambuf.ih"

void MsgStreambuf::atNewline()
{
    if (not d_newMsg or not d_ostr->good())
        return;

    d_newMsg = false;

    if (d_tag.length())
        showTag();

    if (d_showLineNrs)
        *d_ostr << "Line " << d_count << ": ";
}
