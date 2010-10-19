#include "msgstreambuf.ih"

void MsgStreambuf::setTag(string const &tag)
{
    if (tag.length())
        d_tag = '[' + tag;
}
