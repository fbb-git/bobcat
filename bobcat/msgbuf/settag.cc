#include "msgbuf.ih"

void Msgbuf::setTag(string const &tag)
{
    d_tag = tag.length() ? '[' + tag : tag;
}
