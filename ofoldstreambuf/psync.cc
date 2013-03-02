#include "ofoldstreambuf.ih"

int OFoldStreambuf::pSync()
{
    if (d_mode == NON_WS)
        flush();

    out().rdbuf()->pubsync();
    return 0;
}



