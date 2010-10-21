#include "msgbuf.ih"

void Msgbuf::setTag(string const &tag)
{
    if (tag.length())
        d_tag = '[' + tag;
}
