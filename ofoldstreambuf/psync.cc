#include "ofoldstreambuf.hh"

int OFoldStreambuf::pSync()
{
    if (d_mode == NON_WS)
        flush();

    out().rdbuf()->pubsync();
    return 0;
}



