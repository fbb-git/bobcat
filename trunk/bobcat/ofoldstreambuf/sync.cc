#include "ofoldstreambuf.ih"

int OFoldStreambuf::sync()
{
    if (d_mode == NON_WS)
        flush();

    out().rdbuf()->pubsync();
    return 0;
}



