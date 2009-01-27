#include "foldstreambuf.ih"

void FoldStreambuf::clearWs()
{
    d_ws.clear();
    d_wsLength = 0;
}
