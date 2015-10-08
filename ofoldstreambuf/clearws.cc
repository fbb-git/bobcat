#include "ofoldstreambuf.ih"

void OFoldStreambuf::clearWs()
{
    d_ws.clear();
    d_wsLength = 0;
}
