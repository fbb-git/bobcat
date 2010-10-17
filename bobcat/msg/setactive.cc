#include "msg.ih"

void Msg::setActive(StreamInfo &si, bool active)
{
    if (active)
        activateStream(si);
    else
        suppressStream(si);
}

