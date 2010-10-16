#include "msg.ih"

bool Msg::setActive(StreamInfo &si, bool active)
{
    if (active)
        activateStream(si);
    else
        suppressStream(si);

    return active;
}

