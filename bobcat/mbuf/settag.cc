#include "mbuf.ih"

void Mbuf::setTag(string const &tag)
{
    d_tag = tag.length() ? '[' + tag : tag;
}
