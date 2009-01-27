#include "foldstreambuf.ih"

int FoldStreambuf::sync()
{
    if (d_mode == NON_WS)
        flush();

    d_out->rdbuf()->pubsync();
    return 0;
}



