#include "ofoldstreambuf.ih"

OFoldStreambuf::~OFoldStreambuf()
{
    s_buffers.erase(findOFoldStreambuf(this));

    if (d_mode == NON_WS)
        flush();
    else if (d_mode == WS)
    {
        if (d_handleTrailingBlanks)
        {
            if (length() <= d_rightMargin)
                writeWs();
            else
                put('\n');
        }
    }
    out().rdbuf()->pubsync();
}
