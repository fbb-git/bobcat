#include "mbuf.hh"

void Mbuf::setTag(string const &tag)
{
    d_tag = not tag.empty() && (tag.front() != '[') ? '[' + tag : tag;
}
