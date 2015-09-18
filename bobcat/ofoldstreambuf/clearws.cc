#include "ofoldstreambuf.hh"

void OFoldStreambuf::clearWs()
{
    d_ws.clear();
    d_wsLength = 0;
}
