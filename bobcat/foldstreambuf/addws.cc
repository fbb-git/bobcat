#include "foldstreambuf.ih"

void FoldStreambuf::addWs(int c)
{
    if (c != '\t')
        ++d_wsLength;
    else
    {
        size_t wsLen = d_next + d_wsLength;
        d_wsLength = ((wsLen + 8) & ~7) - wsLen;
    }
    d_ws += c;
}
