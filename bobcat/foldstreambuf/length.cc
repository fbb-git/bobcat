#include "foldstreambuf.ih"

size_t FoldStreambuf::length() const
{
    return d_next + d_wsLength + d_nonWs.length();
}
