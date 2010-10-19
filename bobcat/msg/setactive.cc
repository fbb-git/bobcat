#include "msg.ih"

void Msg::setActive(MsgStream *ms, bool active)
{
    if (active)
        activateStream(ms);
    else
        suppressStream(ms);
}

