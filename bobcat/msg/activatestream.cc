#include "msg.ih"

void Msg::activateStream(StreamInfo &si)
{
    if (si.out.good())
        return;

    si.out.clear();
}

